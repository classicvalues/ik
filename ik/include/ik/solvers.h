#ifndef IK_SOLVERS_H
#define IK_SOLVERS_H

#include "ik/config.h"
#include "ik/refcount.h"
#include "cstructures/vector.h"

C_BEGIN

struct ik_solver;
struct ik_algorithm;
struct ik_subtree;
struct ik_node;

typedef void(*ik_solver_callback_func)(void* user_data,
                                       const ikreal position[3],
                                       const ikreal rotation[4]);

struct ik_solver_interface
{
    char name[16];
    uintptr_t size;
    int (*init)(struct ik_solver*);
    void (*deinit)(struct ik_solver*);
    int (*rebuild)(struct ik_solver*, const struct ik_subtree*);
    void (*update_translations)(struct ik_solver*);
    int (*solve)(struct ik_solver*);
    void (*iterate_nodes)(const struct ik_solver*, ik_solver_callback_func);
};

IK_PRIVATE_API int
ik_solver_init_interfaces(void);

IK_PRIVATE_API void
ik_solver_deinit_interfaces(void);

IK_PUBLIC_API int
ik_solver_register(const struct ik_solver_interface* interface);

IK_PUBLIC_API int
ik_solver_unregister(const struct ik_solver_interface* interface);

#define IK_SOLVER_HEAD                                                        \
    const struct ik_solver_interface* impl;                                   \
    const struct ik_algorithm* algorithm;

struct ik_solvers
{
    IK_REFCOUNTED_HEAD
    struct vector_t solver_list;  /* list of ik_solver* */
};

/*!
 * @brief Allocates a new solver object according to the specified solver.
 *
 * Once the solver is created, you can configure the solver to enable/disable
 * various features depending on your needs.
 *
 * The following attributes can be changed at any point.
 *  + solver->max_iterations
 *       Specifies the maximum number of iterations. The more iterations, the
 *       more exact the result will be. The default value for the FABRIK solver
 *       is 20, but you can get away with values as low as 5.
 *  + solver->tolerance
 *       This value can be changed at any point. Specifies the acceptable
 *       distance each effector needs to be to its target position. The solver
 *       will stop iterating if the effectors are within this distance. The
 *       default value is 1e-3. Recommended values are 100th of your world
 *       unit.
 *  + solver->flags
 *       Changes the behaviour of the solver. See the enum solver_flags_e for
 *       more information.
 *
 * The following attributes can be accessed (read from) but should not be
 * modified.
 *  + solver->tree
 *       The tree to be solved. You may modify the nodes in the tree.
 *       @note If you add/remove nodes or if you add/remove effectors, you
 *       must call ik_solver_rebuild_data() so the internal solver structures
 *       are updated. Failing to do so may cause segfaults. If you're just
 *       updating positions/rotations or any of the other public data then
 *       there is no need to rebuild daIK_ALGORITHM_LISTta.
 *  + solver->effector_nodes_list
 *       A vector containing pointers to nodes in the tree which have an
 *       effector attached to them. You may not modify this list, but you may
 *       iterate it.
 * @param[in] solver The solver to use. Currently, only FABRIK is
 * supported.
 */
IK_PUBLIC_API struct ik_solvers*
ik_solvers_create(const struct ik_node* root);

IK_PUBLIC_API int
ik_solvers_rebuild(struct ik_solvers* solver, const struct ik_node* root);

/*!
 * @brief Computes the distances between the nodes and stores them in
 * node->dist_to_parent. The positions used for this computation are those of
 * the active pose (node->position). For this reason, make sure that you've
 * correctly initialized the active pose before calling this function.
 *
 * The segment lengths are typically computed once during initialisation and
 * then never again. Of course, there are exceptions, such as when your tree
 * has translational motions. In this case, you will have to recalculate the
 * segment lengths every time node positions change.
 *
 * @note This function gets called by ik_solver_prepare().
 */
IK_PRIVATE_API void
ik_solvers_update_translations(struct ik_solvers* solver);

IK_PUBLIC_API int
ik_solvers_solve(const struct ik_solvers* solver);

IK_PUBLIC_API void
ik_solvers_iterate_nodes(const struct ik_solvers* solver, ik_solver_callback_func cb);

C_END

#endif /* IK_SOLVER_H */