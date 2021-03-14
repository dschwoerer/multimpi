#include "mpi.h"
#include <stdio.h>

MPI_Comm mpi_COMM_WORLD = MPI_COMM_WORLD;
MPI_Comm mpi_COMM_NULL = MPI_COMM_NULL;
MPI_Datatype mpi_DOUBLE = MPI_DOUBLE;
MPI_Datatype mpi_INT = MPI_INT;
MPI_Datatype mpi_BYTE = MPI_BYTE;
MPI_Datatype mpi_C_BOOL = MPI_C_BOOL;
MPI_Op mpi_MAX = MPI_MAX;
MPI_Op mpi_MIN = MPI_MIN;
MPI_Op mpi_SUM = MPI_SUM;
MPI_Op mpi_LOR = MPI_LOR;
MPI_Op mpi_BOR = MPI_BOR;
MPI_Request mpi_REQUEST_NULL = MPI_REQUEST_NULL;
MPI_Group mpi_GROUP_EMPTY = MPI_GROUP_EMPTY;
int mpi_SUCCESS = MPI_SUCCESS;
int mpi_UNDEFINED = MPI_UNDEFINED;

int mpi_File_write_all(MPI_File fh, ROMIO_CONST void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return MPI_File_write_all(fh, buf, count, datatype, status); }

int mpi_Scatterv(const void *sendbuf, const int *sendcounts, const int *displs, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, void *comm) { return MPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm); }

int mpi_File_write_all_begin(MPI_File fh, ROMIO_CONST void *buf, int count, MPI_Datatype datatype) { return MPI_File_write_all_begin(fh, buf, count, datatype); }

int mpi_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm) { return MPI_Send(buf, count, datatype, dest, tag, comm); }

int mpi_File_write_all_end(MPI_File fh, ROMIO_CONST void *buf, MPI_Status *status) { return MPI_File_write_all_end(fh, buf, status); }

int mpi_Send_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm, MPI_Request *request) { return MPI_Send_init(buf, count, datatype, dest, tag, comm, request); }

int mpi_Abort(void *comm, int errorcode) { return MPI_Abort(comm, errorcode); }

int mpi_File_write_at(MPI_File fh, MPI_Offset offset, ROMIO_CONST void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return MPI_File_write_at(fh, offset, buf, count, datatype, status); }

int mpi_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, void *comm, MPI_Status *status) { return MPI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status); }

int mpi_Accumulate(const void *origin_addr, int origin_count, MPI_Datatype
                   origin_datatype, int target_rank, MPI_Aint
                   target_disp, int target_count, MPI_Datatype
                   target_datatype, MPI_Op op, MPI_Win win) { return MPI_Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win); }

int mpi_File_write_at_all(MPI_File fh, MPI_Offset offset, ROMIO_CONST void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return MPI_File_write_at_all(fh, offset, buf, count, datatype, status); }

int mpi_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, void *comm, MPI_Status *status) { return MPI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status); }

int mpi_Add_error_class(int *errorclass) { return MPI_Add_error_class(errorclass); }

int mpi_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, ROMIO_CONST void *buf, int count, MPI_Datatype datatype) { return MPI_File_write_at_all_begin(fh, offset, buf, count, datatype); }

int mpi_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm) { return MPI_Ssend(buf, count, datatype, dest, tag, comm); }

int mpi_Add_error_code(int errorclass, int *errorcode) { return MPI_Add_error_code(errorclass, errorcode); }

int mpi_File_write_at_all_end(MPI_File fh, ROMIO_CONST void *buf, MPI_Status *status) { return MPI_File_write_at_all_end(fh, buf, status); }

int mpi_Ssend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm, MPI_Request *request) { return MPI_Ssend_init(buf, count, datatype, dest, tag, comm, request); }

int mpi_Add_error_string(int errorcode, const char *string) { return MPI_Add_error_string(errorcode, string); }

int mpi_File_write_ordered(MPI_File fh, ROMIO_CONST void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return MPI_File_write_ordered(fh, buf, count, datatype, status); }

int mpi_Start(MPI_Request *request) { return MPI_Start(request); }

int mpi_Address(const void *location, MPI_Aint *address) { return MPI_Address(location, address); }

int mpi_File_write_ordered_begin(MPI_File fh, ROMIO_CONST void *buf, int count, MPI_Datatype datatype) { return MPI_File_write_ordered_begin(fh, buf, count, datatype); }

int mpi_Startall(int count, MPI_Request array_of_requests[]) { return MPI_Startall(count, array_of_requests); }

int mpi_Allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, void *comm) { return MPI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }

int mpi_File_write_ordered_end(MPI_File fh, ROMIO_CONST void *buf, MPI_Status *status) { return MPI_File_write_ordered_end(fh, buf, status); }

int mpi_Status_set_cancelled(MPI_Status *status, int flag) { return MPI_Status_set_cancelled(status, flag); }

int mpi_Allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int *recvcounts, const int *displs, MPI_Datatype recvtype, void *comm) { return MPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm); }

int mpi_File_write_shared(MPI_File fh, ROMIO_CONST void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return MPI_File_write_shared(fh, buf, count, datatype, status); }

int mpi_Status_set_elements(MPI_Status *status, MPI_Datatype datatype, int count) { return MPI_Status_set_elements(status, datatype, count); }

int mpi_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr) { return MPI_Alloc_mem(size, info, baseptr); }

int mpi_Finalize() { return MPI_Finalize(); }

int mpi_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype, MPI_Count count) { return MPI_Status_set_elements_x(status, datatype, count); }

int mpi_Allreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, void *comm) { return MPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm); }

int mpi_Finalized(int *flag) { return MPI_Finalized(flag); }

int mpi_T_category_changed(int *stamp) { return MPI_T_category_changed(stamp); }

int mpi_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, void *comm) { return MPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }

int mpi_Free_mem(void *base) { return MPI_Free_mem(base); }

int mpi_T_category_get_categories(int cat_index, int len, int indices[]) { return MPI_T_category_get_categories(cat_index, len, indices); }

int mpi_Alltoallv(const void *sendbuf, const int *sendcounts, const int *sdispls, MPI_Datatype sendtype, void *recvbuf, const int *recvcounts, const int *rdispls, MPI_Datatype recvtype, void *comm) { return MPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm); }

int mpi_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, void *comm) { return MPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm); }

int mpi_T_category_get_cvars(int cat_index, int len, int indices[]) { return MPI_T_category_get_cvars(cat_index, len, indices); }

int mpi_Alltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], void *comm) { return MPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm); }

int mpi_Gatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int *recvcounts, const int *displs, MPI_Datatype recvtype, int root, void *comm) { return MPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm); }

int mpi_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len, int *num_cvars, int *num_pvars, int *num_categories) { return MPI_T_category_get_info(cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories); }

int mpi_Attr_delete(void *comm, int keyval) { return MPI_Attr_delete(comm, keyval); }

int mpi_Get(void *origin_addr, int origin_count, MPI_Datatype
            origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win
            win) { return MPI_Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win); }

int mpi_T_category_get_num(int *num_cat) { return MPI_T_category_get_num(num_cat); }

int mpi_Attr_get(void *comm, int keyval, void *attribute_val, int *flag) { return MPI_Attr_get(comm, keyval, attribute_val, flag); }

int mpi_Get_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) { return MPI_Get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win); }

int mpi_T_category_get_pvars(int cat_index, int len, int indices[]) { return MPI_T_category_get_pvars(cat_index, len, indices); }

int mpi_Attr_put(void *comm, int keyval, void *attribute_val) { return MPI_Attr_put(comm, keyval, attribute_val); }

int mpi_Get_address(const void *location, MPI_Aint *address) { return MPI_Get_address(location, address); }

int mpi_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *binding, int *scope) { return MPI_T_cvar_get_info(cvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, binding, scope); }

int mpi_Barrier(void *comm) { return MPI_Barrier(comm); }

int mpi_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count) { return MPI_Get_count(status, datatype, count); }

int mpi_T_cvar_get_num(int *num_cvar) { return MPI_T_cvar_get_num(num_cvar); }

int mpi_Bcast(void *buffer, int count, MPI_Datatype datatype, int root, void *comm) { return MPI_Bcast(buffer, count, datatype, root, comm); }

int mpi_Get_elements(const MPI_Status *status, MPI_Datatype datatype, int *count) { return MPI_Get_elements(status, datatype, count); }

int mpi_T_cvar_handle_alloc(int cvar_index, void *obj_handle, MPI_T_cvar_handle *handle, int *count) { return MPI_T_cvar_handle_alloc(cvar_index, obj_handle, handle, count); }

int mpi_Bsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm) { return MPI_Bsend(buf, count, datatype, dest, tag, comm); }

int mpi_Get_elements_x(const MPI_Status *status, MPI_Datatype datatype, MPI_Count *count) { return MPI_Get_elements_x(status, datatype, count); }

int mpi_T_cvar_handle_free(MPI_T_cvar_handle *handle) { return MPI_T_cvar_handle_free(handle); }

int mpi_Bsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm, MPI_Request *request) { return MPI_Bsend_init(buf, count, datatype, dest, tag, comm, request); }

int mpi_Get_library_version(char *version, int *resultlen) { return MPI_Get_library_version(version, resultlen); }

int mpi_T_cvar_read(MPI_T_cvar_handle handle, void *buf) { return MPI_T_cvar_read(handle, buf); }

int mpi_Buffer_attach(void *buffer, int size) { return MPI_Buffer_attach(buffer, size); }

int mpi_Get_processor_name(char *name, int *resultlen) { return MPI_Get_processor_name(name, resultlen); }

int mpi_T_cvar_write(MPI_T_cvar_handle handle, void *buf) { return MPI_T_cvar_write(handle, buf); }

int mpi_Buffer_detach(void *buffer_addr, int *size) { return MPI_Buffer_detach(buffer_addr, size); }

int mpi_Get_version(int *version, int *subversion) { return MPI_Get_version(version, subversion); }

int mpi_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name, int *name_len) { return MPI_T_enum_get_info(enumtype, num, name, name_len); }

int mpi_Cancel(MPI_Request *request) { return MPI_Cancel(request); }

int mpi_Graph_create(void *comm_old, int nnodes, const int indx[], const int edges[], int reorder, void **comm_graph) { return MPI_Graph_create(comm_old, nnodes, indx, edges, reorder, comm_graph); }

int mpi_T_enum_get_item(MPI_T_enum enumtype, int index, int *value, char *name, int *name_len) { return MPI_T_enum_get_item(enumtype, index, value, name, name_len); }

int mpi_Cart_coords(void *comm, int rank, int maxdims, int coords[]) { return MPI_Cart_coords(comm, rank, maxdims, coords); }

int mpi_Graph_get(void *comm, int maxindex, int maxedges, int indx[], int edges[]) { return MPI_Graph_get(comm, maxindex, maxedges, indx, edges); }

int mpi_T_finalize() { return MPI_T_finalize(); }

int mpi_Cart_create(void *comm_old, int ndims, const int dims[], const int periods[], int reorder, void **comm_cart) { return MPI_Cart_create(comm_old, ndims, dims, periods, reorder, comm_cart); }

int mpi_Graph_map(void *comm, int nnodes, const int indx[], const int edges[], int *newrank) { return MPI_Graph_map(comm, nnodes, indx, edges, newrank); }

int mpi_T_init_thread(int required, int *provided) { return MPI_T_init_thread(required, provided); }

int mpi_Cart_get(void *comm, int maxdims, int dims[], int periods[], int coords[]) { return MPI_Cart_get(comm, maxdims, dims, periods, coords); }

int mpi_Graph_neighbors(void *comm, int rank, int maxneighbors, int neighbors[]) { return MPI_Graph_neighbors(comm, rank, maxneighbors, neighbors); }

int mpi_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class, MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len, int *binding, int *readonly, int *continuous, int *atomic) { return MPI_T_pvar_get_info(pvar_index, name, name_len, verbosity, var_class, datatype, enumtype, desc, desc_len, binding, readonly, continuous, atomic); }

int mpi_Cart_map(void *comm, int ndims, const int dims[], const int periods[], int *newrank) { return MPI_Cart_map(comm, ndims, dims, periods, newrank); }

int mpi_Graph_neighbors_count(void *comm, int rank, int *nneighbors) { return MPI_Graph_neighbors_count(comm, rank, nneighbors); }

int mpi_T_pvar_get_num(int *num_pvar) { return MPI_T_pvar_get_num(num_pvar); }

int mpi_Cart_rank(void *comm, const int coords[], int *rank) { return MPI_Cart_rank(comm, coords, rank); }

int mpi_Graphdims_get(void *comm, int *nnodes, int *nedges) { return MPI_Graphdims_get(comm, nnodes, nedges); }

int mpi_T_pvar_handle_alloc(MPI_T_pvar_session session, int pvar_index, void *obj_handle, MPI_T_pvar_handle *handle, int *count) { return MPI_T_pvar_handle_alloc(session, pvar_index, obj_handle, handle, count); }

int mpi_Cart_shift(void *comm, int direction, int disp, int *rank_source, int *rank_dest) { return MPI_Cart_shift(comm, direction, disp, rank_source, rank_dest); }

int mpi_Grequest_complete(MPI_Request request) { return MPI_Grequest_complete(request); }

int mpi_T_pvar_handle_free(MPI_T_pvar_session session, MPI_T_pvar_handle *handle) { return MPI_T_pvar_handle_free(session, handle); }

int mpi_Cart_sub(void *comm, const int remain_dims[], void **newcomm) { return MPI_Cart_sub(comm, remain_dims, newcomm); }

int mpi_Grequest_start(MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn, MPI_Grequest_cancel_function *cancel_fn, void *extra_state, MPI_Request *request) { return MPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, request); }

int mpi_T_pvar_read(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf) { return MPI_T_pvar_read(session, handle, buf); }

int mpi_Cartdim_get(void *comm, int *ndims) { return MPI_Cartdim_get(comm, ndims); }

int mpi_Group_compare(MPI_Group group1, MPI_Group group2, int *result) { return MPI_Group_compare(group1, group2, result); }

int mpi_T_pvar_readreset(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf) { return MPI_T_pvar_readreset(session, handle, buf); }

int mpi_Close_port(const char *port_name) { return MPI_Close_port(port_name); }

int mpi_Group_difference(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) { return MPI_Group_difference(group1, group2, newgroup); }

int mpi_T_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle) { return MPI_T_pvar_reset(session, handle); }

int mpi_Comm_accept(const char *port_name, MPI_Info info, int root, void *comm, void **newcomm) { return MPI_Comm_accept(port_name, info, root, comm, newcomm); }

int mpi_Group_excl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup) { return MPI_Group_excl(group, n, ranks, newgroup); }

int mpi_T_pvar_session_create(MPI_T_pvar_session *session) { return MPI_T_pvar_session_create(session); }

int mpi_Comm_call_errhandler(void *comm, int errorcode) { return MPI_Comm_call_errhandler(comm, errorcode); }

int mpi_Group_free(MPI_Group *group) { return MPI_Group_free(group); }

int mpi_T_pvar_session_free(MPI_T_pvar_session *session) { return MPI_T_pvar_session_free(session); }

int mpi_Comm_compare(void *comm1, void *comm2, int *result) { return MPI_Comm_compare(comm1, comm2, result); }

int mpi_Group_incl(MPI_Group group, int n, const int ranks[], MPI_Group *newgroup) { return MPI_Group_incl(group, n, ranks, newgroup); }

int mpi_T_pvar_start(MPI_T_pvar_session session, MPI_T_pvar_handle handle) { return MPI_T_pvar_start(session, handle); }

int mpi_Comm_connect(const char *port_name, MPI_Info info, int root, void *comm, void **newcomm) { return MPI_Comm_connect(port_name, info, root, comm, newcomm); }

int mpi_Group_intersection(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) { return MPI_Group_intersection(group1, group2, newgroup); }

int mpi_T_pvar_stop(MPI_T_pvar_session session, MPI_T_pvar_handle handle) { return MPI_T_pvar_stop(session, handle); }

int mpi_Comm_create(void *comm, MPI_Group group, void **newcomm) { return MPI_Comm_create(comm, group, newcomm); }

int mpi_Group_range_excl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup) { return MPI_Group_range_excl(group, n, ranges, newgroup); }

int mpi_T_pvar_write(MPI_T_pvar_session session, MPI_T_pvar_handle handle, void *buf) { return MPI_T_pvar_write(session, handle, buf); }

int mpi_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn, MPI_Errhandler *errhandler) { return MPI_Comm_create_errhandler(comm_errhandler_fn, errhandler); }

int mpi_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group *newgroup) { return MPI_Group_range_incl(group, n, ranges, newgroup); }

int mpi_Test(MPI_Request *request, int *flag, MPI_Status *status) { return MPI_Test(request, flag, status); }

int mpi_Comm_create_group(void *comm, MPI_Group group, int tag, void ** newcomm) { return MPI_Comm_create_group(comm, group, tag, newcomm); }

int mpi_Group_rank(MPI_Group group, int *rank) { return MPI_Group_rank(group, rank); }

int mpi_Test_cancelled(const MPI_Status *status, int *flag) { return MPI_Test_cancelled(status, flag); }

int mpi_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn, MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval, void *extra_state) { return MPI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state); }

int mpi_Group_size(MPI_Group group, int *size) { return MPI_Group_size(group, size); }

int mpi_Testall(int count, MPI_Request array_of_requests[], int *flag, MPI_Status array_of_statuses[]) { return MPI_Testall(count, array_of_requests, flag, array_of_statuses); }

int mpi_Comm_delete_attr(void *comm, int comm_keyval) { return MPI_Comm_delete_attr(comm, comm_keyval); }

int mpi_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[], MPI_Group group2, int ranks2[]) { return MPI_Group_translate_ranks(group1, n, ranks1, group2, ranks2); }

int mpi_Testany(int count, MPI_Request array_of_requests[], int *indx, int *flag, MPI_Status *status) { return MPI_Testany(count, array_of_requests, indx, flag, status); }

int mpi_Comm_disconnect(void ** comm) { return MPI_Comm_disconnect(comm); }

int mpi_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) { return MPI_Group_union(group1, group2, newgroup); }

int mpi_Testsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[]) { return MPI_Testsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses); }

int mpi_Comm_dup(void *comm, void **newcomm) { return MPI_Comm_dup(comm, newcomm); }

int mpi_Iallgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, void *comm, MPI_Request *request) { return MPI_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }

int mpi_Topo_test(void *comm, int *status) { return MPI_Topo_test(comm, status); }

int mpi_Comm_dup_with_info(void *comm, MPI_Info info, void ** newcomm) { return MPI_Comm_dup_with_info(comm, info, newcomm); }

int mpi_Iallgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, void *comm, MPI_Request *request) { return MPI_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request); }

int mpi_Type_commit(MPI_Datatype *datatype) { return MPI_Type_commit(datatype); }

int mpi_Comm_free(void **comm) { return MPI_Comm_free(comm); }

int mpi_Iallreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, void *comm, MPI_Request *request) { return MPI_Iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request); }

int mpi_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype) { return MPI_Type_contiguous(count, oldtype, newtype); }

int mpi_Comm_free_keyval(int *comm_keyval) { return MPI_Comm_free_keyval(comm_keyval); }

int mpi_Ialltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, void *comm, MPI_Request *request) { return MPI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }

int mpi_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype) { return MPI_Type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype); }

int mpi_Comm_get_attr(void *comm, int comm_keyval, void *attribute_val, int *flag) { return MPI_Comm_get_attr(comm, comm_keyval, attribute_val, flag); }

int mpi_Ialltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, void *comm, MPI_Request *request) { return MPI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request); }

int mpi_Type_create_f90_complex(int precision, int range, MPI_Datatype *newtype) { return MPI_Type_create_f90_complex(precision, range, newtype); }

int mpi_Comm_get_errhandler(void *comm, MPI_Errhandler *errhandler) { return MPI_Comm_get_errhandler(comm, errhandler); }

int mpi_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const MPI_Datatype recvtypes[], void *comm, MPI_Request *request) { return MPI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request); }

int mpi_Type_create_f90_integer(int range, MPI_Datatype *newtype) { return MPI_Type_create_f90_integer(range, newtype); }

int mpi_Comm_get_info(void *comm, MPI_Info * info_used) { return MPI_Comm_get_info(comm, info_used); }

int mpi_Ibarrier(void *comm, MPI_Request *request) { return MPI_Ibarrier(comm, request); }

int mpi_Type_create_f90_real(int precision, int range, MPI_Datatype *newtype) { return MPI_Type_create_f90_real(precision, range, newtype); }

int mpi_Comm_get_name(void *comm, char *comm_name, int *resultlen) { return MPI_Comm_get_name(comm, comm_name, resultlen); }

int mpi_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root, void *comm, MPI_Request *request) { return MPI_Ibcast(buffer, count, datatype, root, comm, request); }

int mpi_Type_create_hindexed(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return MPI_Type_create_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype); }

int mpi_Comm_get_parent(void **parent) { return MPI_Comm_get_parent(parent); }

int mpi_Ibsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm, MPI_Request *request) { return MPI_Ibsend(buf, count, datatype, dest, tag, comm, request); }

int mpi_Type_create_hindexed_block(int count, int blocklength, const MPI_Aint array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype * newtype) { return MPI_Type_create_hindexed_block(count, blocklength, array_of_displacements, oldtype, newtype); }

int mpi_Comm_group(void *comm, MPI_Group *group) { return MPI_Comm_group(comm, group); }

int mpi_Iexscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, void *comm, MPI_Request *request) { return MPI_Iexscan(sendbuf, recvbuf, count, datatype, op, comm, request); }

int mpi_Type_create_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { return MPI_Type_create_hvector(count, blocklength, stride, oldtype, newtype); }

int mpi_Comm_idup(void *comm, void **newcomm, MPI_Request *request) { return MPI_Comm_idup(comm, newcomm, request); }

int mpi_Igather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, void *comm, MPI_Request *request) { return MPI_Igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request); }

int mpi_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[], MPI_Datatype oldtype, MPI_Datatype *newtype) { return MPI_Type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype); }

int mpi_Comm_join(int fd, void **intercomm) { return MPI_Comm_join(fd, intercomm); }

int mpi_Igatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, int root, void *comm, MPI_Request *request) { return MPI_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request); }

int mpi_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn, MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval, void *extra_state) { return MPI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state); }

int mpi_Comm_rank(void *comm, int *rank) { return MPI_Comm_rank(comm, rank); }

int mpi_Improbe(int source, int tag, void *comm, int *flag, MPI_Message *message, MPI_Status *status) { return MPI_Improbe(source, tag, comm, flag, message, status); }

int mpi_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent, MPI_Datatype *newtype) { return MPI_Type_create_resized(oldtype, lb, extent, newtype); }

int mpi_Comm_remote_group(void *comm, MPI_Group *group) { return MPI_Comm_remote_group(comm, group); }

int mpi_Imrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Request *request) { return MPI_Imrecv(buf, count, datatype, message, request); }

int mpi_Type_create_struct(int count, const int array_of_blocklengths[], const MPI_Aint array_of_displacements[], const MPI_Datatype array_of_types[], MPI_Datatype *newtype) { return MPI_Type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype); }

int mpi_Comm_remote_size(void *comm, int *size) { return MPI_Comm_remote_size(comm, size); }

int mpi_Ineighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, void *comm, MPI_Request *request) { return MPI_Ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }

int mpi_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int order, MPI_Datatype oldtype, MPI_Datatype *newtype) { return MPI_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype); }

int mpi_Comm_set_attr(void *comm, int comm_keyval, void *attribute_val) { return MPI_Comm_set_attr(comm, comm_keyval, attribute_val); }

int mpi_Ineighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, void *comm, MPI_Request *request) { return MPI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request); }

int mpi_Type_delete_attr(MPI_Datatype datatype, int type_keyval) { return MPI_Type_delete_attr(datatype, type_keyval); }

int mpi_Comm_set_errhandler(void *comm, MPI_Errhandler errhandler) { return MPI_Comm_set_errhandler(comm, errhandler); }

int mpi_Ineighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, void *comm, MPI_Request *request) { return MPI_Ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request); }

int mpi_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype) { return MPI_Type_dup(oldtype, newtype); }

int mpi_Comm_set_info(void *comm, MPI_Info info) { return MPI_Comm_set_info(comm, info); }

int mpi_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, void *comm, MPI_Request *request) { return MPI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request); }

int mpi_Type_extent(MPI_Datatype datatype, MPI_Aint *extent) { return MPI_Type_extent(datatype, extent); }

int mpi_Comm_set_name(void *comm, const char *comm_name) { return MPI_Comm_set_name(comm, comm_name); }

int mpi_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], void *comm, MPI_Request *request) { return MPI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request); }

int mpi_Type_free(MPI_Datatype *datatype) { return MPI_Type_free(datatype); }

int mpi_Comm_size(void *comm, int *size) { return MPI_Comm_size(comm, size); }

int mpi_Info_create(MPI_Info *info) { return MPI_Info_create(info); }

int mpi_Type_free_keyval(int *type_keyval) { return MPI_Type_free_keyval(type_keyval); }

int mpi_Comm_spawn(const char *command, char *argv[], int maxprocs, MPI_Info info, int root, void *comm, void **intercomm, int array_of_errcodes[]) { return MPI_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes); }

int mpi_Info_delete(MPI_Info info, const char *key) { return MPI_Info_delete(info, key); }

int mpi_Type_get_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag) { return MPI_Type_get_attr(datatype, type_keyval, attribute_val, flag); }

int mpi_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], const int array_of_maxprocs[], const MPI_Info array_of_info[], int root, void *comm, void **intercomm, int array_of_errcodes[]) { return MPI_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes); }

int mpi_Info_dup(MPI_Info info, MPI_Info *newinfo) { return MPI_Info_dup(info, newinfo); }

int mpi_Type_get_contents(MPI_Datatype datatype, int max_integers, int max_addresses, int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[], MPI_Datatype array_of_datatypes[]) { return MPI_Type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes); }

int mpi_Comm_split(void *comm, int color, int key, void **newcomm) { return MPI_Comm_split(comm, color, key, newcomm); }

int mpi_Info_free(MPI_Info *info) { return MPI_Info_free(info); }

int mpi_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner) { return MPI_Type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner); }

int mpi_Comm_split_type(void *comm, int split_type, int key, MPI_Info info, void ** newcomm) { return MPI_Comm_split_type(comm, split_type, key, info, newcomm); }

int mpi_Info_get(MPI_Info info, const char *key, int valuelen, char *value, int *flag) { return MPI_Info_get(info, key, valuelen, value, flag); }

int mpi_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent) { return MPI_Type_get_extent(datatype, lb, extent); }

int mpi_Comm_test_inter(void *comm, int *flag) { return MPI_Comm_test_inter(comm, flag); }

int mpi_Info_get_nkeys(MPI_Info info, int *nkeys) { return MPI_Info_get_nkeys(info, nkeys); }

int mpi_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb, MPI_Count *extent) { return MPI_Type_get_extent_x(datatype, lb, extent); }

int mpi_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win) { return MPI_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win); }

int mpi_Info_get_nthkey(MPI_Info info, int n, char *key) { return MPI_Info_get_nthkey(info, n, key); }

int mpi_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen) { return MPI_Type_get_name(datatype, type_name, resultlen); }

int mpi_Dims_create(int nnodes, int ndims, int dims[]) { return MPI_Dims_create(nnodes, ndims, dims); }

int mpi_Info_get_valuelen(MPI_Info info, const char *key, int *valuelen, int *flag) { return MPI_Info_get_valuelen(info, key, valuelen, flag); }

int mpi_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb, MPI_Aint *true_extent) { return MPI_Type_get_true_extent(datatype, true_lb, true_extent); }

int mpi_Dist_graph_create(void *comm_old, int n, const int sources[], const int degrees[], const int destinations[], const int weights[], MPI_Info info, int reorder, void **comm_dist_graph) { return MPI_Dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph); }

int mpi_Info_set(MPI_Info info, const char *key, const char *value) { return MPI_Info_set(info, key, value); }

int mpi_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent) { return MPI_Type_get_true_extent_x(datatype, true_lb, true_extent); }

int mpi_Dist_graph_create_adjacent(void *comm_old, int indegree, const int sources[], const int sourceweights[], int outdegree, const int destinations[], const int destweights[], MPI_Info info, int reorder, void **comm_dist_graph) { return MPI_Dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph); }

int mpi_Init(int *argc, char ***argv) { return MPI_Init(argc, argv); }

int mpi_Type_hindexed(int count, const int *array_of_blocklengths, const MPI_Aint *array_of_displacements, MPI_Datatype oldtype, MPI_Datatype *newtype) { return MPI_Type_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype); }

int mpi_Dist_graph_neighbors(void *comm, int maxindegree, int sources[], int sourceweights[], int maxoutdegree, int destinations[], int destweights[]) { return MPI_Dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights); }

int mpi_Init_thread(int *argc, char ***argv, int required, int *provided) { return MPI_Init_thread(argc, argv, required, provided); }

int mpi_Type_hvector(int count, int blocklength, MPI_Aint stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { return MPI_Type_hvector(count, blocklength, stride, oldtype, newtype); }

int mpi_Dist_graph_neighbors_count(void *comm, int *indegree, int *outdegree, int *weighted) { return MPI_Dist_graph_neighbors_count(comm, indegree, outdegree, weighted); }

int mpi_Initialized(int *flag) { return MPI_Initialized(flag); }

int mpi_Type_indexed(int count, const int *array_of_blocklengths, const int *array_of_displacements, MPI_Datatype oldtype, MPI_Datatype *newtype) { return MPI_Type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype); }

int mpi_Errhandler_create(MPI_Handler_function *function, MPI_Errhandler *errhandler) { return MPI_Errhandler_create(function, errhandler); }

int mpi_Intercomm_create(void *local_comm, int local_leader, void *peer_comm, int remote_leader, int tag, void **newintercomm) { return MPI_Intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm); }

int mpi_Type_lb(MPI_Datatype datatype, MPI_Aint *displacement) { return MPI_Type_lb(datatype, displacement); }

int mpi_Errhandler_free(MPI_Errhandler *errhandler) { return MPI_Errhandler_free(errhandler); }

int mpi_Intercomm_merge(void *intercomm, int high, void **newintracomm) { return MPI_Intercomm_merge(intercomm, high, newintracomm); }

int mpi_Type_match_size(int typeclass, int size, MPI_Datatype *datatype) { return MPI_Type_match_size(typeclass, size, datatype); }

int mpi_Errhandler_get(void *comm, MPI_Errhandler *errhandler) { return MPI_Errhandler_get(comm, errhandler); }

int mpi_Iprobe(int source, int tag, void *comm, int *flag, MPI_Status *status) { return MPI_Iprobe(source, tag, comm, flag, status); }

int mpi_Type_set_attr(MPI_Datatype datatype, int type_keyval, void *attribute_val) { return MPI_Type_set_attr(datatype, type_keyval, attribute_val); }

int mpi_Errhandler_set(void *comm, MPI_Errhandler errhandler) { return MPI_Errhandler_set(comm, errhandler); }

int mpi_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, void *comm, MPI_Request *request) { return MPI_Irecv(buf, count, datatype, source, tag, comm, request); }

int mpi_Type_set_name(MPI_Datatype datatype, const char *type_name) { return MPI_Type_set_name(datatype, type_name); }

int mpi_Error_class(int errorcode, int *errorclass) { return MPI_Error_class(errorcode, errorclass); }

int mpi_Ireduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, void *comm, MPI_Request *request) { return MPI_Ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request); }

int mpi_Type_size(MPI_Datatype datatype, int *size) { return MPI_Type_size(datatype, size); }

int mpi_Error_string(int errorcode, char *string, int *resultlen) { return MPI_Error_string(errorcode, string, resultlen); }

int mpi_Ireduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, void *comm, MPI_Request *request) { return MPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request); }

int mpi_Type_size_x(MPI_Datatype datatype, MPI_Count *size) { return MPI_Type_size_x(datatype, size); }

int mpi_Exscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, void *comm) { return MPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm); }

int mpi_Ireduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, void *comm, MPI_Request *request) { return MPI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request); }

int mpi_Type_struct(int count, const int *array_of_blocklengths, const MPI_Aint *array_of_displacements, const MPI_Datatype *array_of_types, MPI_Datatype *newtype) { return MPI_Type_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype); }

int mpi_Fetch_and_op(const void *origin_addr, void *result_addr, MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Op op, MPI_Win win) { return MPI_Fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win); }

int mpi_Irsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm, MPI_Request *request) { return MPI_Irsend(buf, count, datatype, dest, tag, comm, request); }

int mpi_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement) { return MPI_Type_ub(datatype, displacement); }

MPI_Fint mpi_File_c2f(MPI_File fh) { return MPI_File_c2f(fh); }

int mpi_Is_thread_main(int *flag) { return MPI_Is_thread_main(flag); }

int mpi_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype *newtype) { return MPI_Type_vector(count, blocklength, stride, oldtype, newtype); }

int mpi_File_call_errhandler(MPI_File fh, int errorcode) { return MPI_File_call_errhandler(fh, errorcode); }

int mpi_Iscan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, void *comm, MPI_Request *request) { return MPI_Iscan(sendbuf, recvbuf, count, datatype, op, comm, request); }

int mpi_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount, MPI_Datatype datatype, void *comm) { return MPI_Unpack(inbuf, insize, position, outbuf, outcount, datatype, comm); }

int mpi_File_close(MPI_File *fh) { return MPI_File_close(fh); }

int mpi_Iscatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, void *comm, MPI_Request *request) { return MPI_Iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request); }

int mpi_Unpack_external(const char datarep[], const void *inbuf, MPI_Aint insize, MPI_Aint *position, void *outbuf, int outcount, MPI_Datatype datatype) { return MPI_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype); }

int mpi_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn, MPI_Errhandler *errhandler) { return MPI_File_create_errhandler(file_errhandler_fn, errhandler); }

int mpi_Iscatterv(const void *sendbuf, const int sendcounts[], const int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, void *comm, MPI_Request *request) { return MPI_Iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request); }

int mpi_Unpublish_name(const char *service_name, MPI_Info info, const char *port_name) { return MPI_Unpublish_name(service_name, info, port_name); }

int mpi_File_delete(ROMIO_CONST char *filename, MPI_Info info) { return MPI_File_delete(filename, info); }

int mpi_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm, MPI_Request *request) { return MPI_Isend(buf, count, datatype, dest, tag, comm, request); }

int mpi_Wait(MPI_Request *request, MPI_Status *status) { return MPI_Wait(request, status); }

MPI_File mpi_File_f2c(MPI_Fint fh) { return MPI_File_f2c(fh); }

int mpi_Issend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm, MPI_Request *request) { return MPI_Issend(buf, count, datatype, dest, tag, comm, request); }

int mpi_Waitall(int count, MPI_Request array_of_requests[], MPI_Status array_of_statuses[]) { return MPI_Waitall(count, array_of_requests, array_of_statuses); }

int mpi_File_get_amode(MPI_File fh, int *amode) { return MPI_File_get_amode(fh, amode); }

int mpi_Keyval_create(MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval, void *extra_state) { return MPI_Keyval_create(copy_fn, delete_fn, keyval, extra_state); }

int mpi_Waitany(int count, MPI_Request array_of_requests[], int *indx, MPI_Status *status) { return MPI_Waitany(count, array_of_requests, indx, status); }

int mpi_File_get_atomicity(MPI_File fh, int *flag) { return MPI_File_get_atomicity(fh, flag); }

int mpi_Keyval_free(int *keyval) { return MPI_Keyval_free(keyval); }

int mpi_Waitsome(int incount, MPI_Request array_of_requests[], int *outcount, int array_of_indices[], MPI_Status array_of_statuses[]) { return MPI_Waitsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses); }

int mpi_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp) { return MPI_File_get_byte_offset(fh, offset, disp); }

int mpi_Lookup_name(const char *service_name, MPI_Info info, char *port_name) { return MPI_Lookup_name(service_name, info, port_name); }

int mpi_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, void *comm, void *baseptr, MPI_Win *win) { return MPI_Win_allocate(size, disp_unit, info, comm, baseptr, win); }

int mpi_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler) { return MPI_File_get_errhandler(file, errhandler); }

int mpi_Mprobe(int source, int tag, void *comm, MPI_Message *message, MPI_Status *status) { return MPI_Mprobe(source, tag, comm, message, status); }

int mpi_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info, void *comm, void *baseptr, MPI_Win *win) { return MPI_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win); }

int mpi_File_get_group(MPI_File fh, MPI_Group *group) { return MPI_File_get_group(fh, group); }

int mpi_Mrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message, MPI_Status *status) { return MPI_Mrecv(buf, count, datatype, message, status); }

int mpi_Win_attach(MPI_Win win, void *base, MPI_Aint size) { return MPI_Win_attach(win, base, size); }

int mpi_File_get_info(MPI_File fh, MPI_Info *info_used) { return MPI_File_get_info(fh, info_used); }

int mpi_Neighbor_allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, void *comm) { return MPI_Neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }

int mpi_Win_call_errhandler(MPI_Win win, int errorcode) { return MPI_Win_call_errhandler(win, errorcode); }

int mpi_File_get_position(MPI_File fh, MPI_Offset *offset) { return MPI_File_get_position(fh, offset); }

int mpi_Neighbor_allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int displs[], MPI_Datatype recvtype, void *comm) { return MPI_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm); }

int mpi_Win_complete(MPI_Win win) { return MPI_Win_complete(win); }

int mpi_File_get_position_shared(MPI_File fh, MPI_Offset *offset) { return MPI_File_get_position_shared(fh, offset); }

int mpi_Neighbor_alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, void *comm) { return MPI_Neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm); }

int mpi_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, void *comm, MPI_Win *win) { return MPI_Win_create(base, size, disp_unit, info, comm, win); }

int mpi_File_get_size(MPI_File fh, MPI_Offset *size) { return MPI_File_get_size(fh, size); }

int mpi_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], MPI_Datatype sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], MPI_Datatype recvtype, void *comm) { return MPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm); }

int mpi_Win_create_dynamic(MPI_Info info, void *comm, MPI_Win *win) { return MPI_Win_create_dynamic(info, comm, win); }

int mpi_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent) { return MPI_File_get_type_extent(fh, datatype, extent); }

int mpi_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[], const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[], const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], void *comm) { return MPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm); }

int mpi_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn, MPI_Errhandler *errhandler) { return MPI_Win_create_errhandler(win_errhandler_fn, errhandler); }

int mpi_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep) { return MPI_File_get_view(fh, disp, etype, filetype, datarep); }

int mpi_Op_commutative(MPI_Op op, int *commute) { return MPI_Op_commutative(op, commute); }

int mpi_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn, MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval, void *extra_state) { return MPI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state); }

int mpi_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return MPI_File_iread(fh, buf, count, datatype, request); }

int mpi_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op) { return MPI_Op_create(user_fn, commute, op); }

int mpi_Win_delete_attr(MPI_Win win, int win_keyval) { return MPI_Win_delete_attr(win, win_keyval); }

int mpi_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPIO_Request *request) { return MPI_File_iread_at(fh, offset, buf, count, datatype, request); }

int mpi_Op_free(MPI_Op *op) { return MPI_Op_free(op); }

int mpi_Win_detach(MPI_Win win, const void *base) { return MPI_Win_detach(win, base); }

int mpi_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return MPI_File_iread_shared(fh, buf, count, datatype, request); }

int mpi_Open_port(MPI_Info info, char *port_name) { return MPI_Open_port(info, port_name); }

int mpi_Win_fence(int assert, MPI_Win win) { return MPI_Win_fence(assert, win); }

int mpi_File_iwrite(MPI_File fh, ROMIO_CONST void *buf, int count, MPI_Datatype datatype, MPI_Request *request) { return MPI_File_iwrite(fh, buf, count, datatype, request); }

int mpi_Pack(const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int outsize, int *position, void *comm) { return MPI_Pack(inbuf, incount, datatype, outbuf, outsize, position, comm); }

int mpi_Win_flush(int rank, MPI_Win win) { return MPI_Win_flush(rank, win); }

int mpi_File_iwrite_at(MPI_File fh, MPI_Offset offset, ROMIO_CONST void *buf, int count, MPI_Datatype datatype, MPIO_Request *request) { return MPI_File_iwrite_at(fh, offset, buf, count, datatype, request); }

int mpi_Pack_external(const char datarep[], const void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, MPI_Aint outsize, MPI_Aint *position) { return MPI_Pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position); }

int mpi_Win_flush_all(MPI_Win win) { return MPI_Win_flush_all(win); }

int mpi_File_iwrite_shared(MPI_File fh, ROMIO_CONST void *buf, int count, MPI_Datatype datatype, MPIO_Request *request) { return MPI_File_iwrite_shared(fh, buf, count, datatype, request); }

int mpi_Pack_external_size(const char datarep[], int incount, MPI_Datatype datatype, MPI_Aint *size) { return MPI_Pack_external_size(datarep, incount, datatype, size); }

int mpi_Win_flush_local(int rank, MPI_Win win) { return MPI_Win_flush_local(rank, win); }

int mpi_File_open(void *comm, ROMIO_CONST char *filename, int amode, MPI_Info info, MPI_File *fh) { return MPI_File_open(comm, filename, amode, info, fh); }

int mpi_Pack_size(int incount, MPI_Datatype datatype, void *comm, int *size) { return MPI_Pack_size(incount, datatype, comm, size); }

int mpi_Win_flush_local_all(MPI_Win win) { return MPI_Win_flush_local_all(win); }

int mpi_File_preallocate(MPI_File fh, MPI_Offset size) { return MPI_File_preallocate(fh, size); }

int mpi_Win_free(MPI_Win *win) { return MPI_Win_free(win); }

int mpi_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return MPI_File_read(fh, buf, count, datatype, status); }

int mpi_Probe(int source, int tag, void *comm, MPI_Status *status) { return MPI_Probe(source, tag, comm, status); }

int mpi_Win_free_keyval(int *win_keyval) { return MPI_Win_free_keyval(win_keyval); }

int mpi_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return MPI_File_read_all(fh, buf, count, datatype, status); }

int mpi_Publish_name(const char *service_name, MPI_Info info, const char *port_name) { return MPI_Publish_name(service_name, info, port_name); }

int mpi_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val, int *flag) { return MPI_Win_get_attr(win, win_keyval, attribute_val, flag); }

int mpi_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) { return MPI_File_read_all_begin(fh, buf, count, datatype); }

int mpi_Put(const void *origin_addr, int origin_count, MPI_Datatype
            origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win
            win) { return MPI_Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win); }

int mpi_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler) { return MPI_Win_get_errhandler(win, errhandler); }

int mpi_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status) { return MPI_File_read_all_end(fh, buf, status); }

int mpi_Query_thread(int *provided) { return MPI_Query_thread(provided); }

int mpi_Win_get_group(MPI_Win win, MPI_Group *group) { return MPI_Win_get_group(win, group); }

int mpi_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return MPI_File_read_at(fh, offset, buf, count, datatype, status); }

int mpi_Raccumulate(const void *origin_addr, int origin_count, MPI_Datatype
                   origin_datatype, int target_rank, MPI_Aint
                   target_disp, int target_count, MPI_Datatype
                   target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) { return MPI_Raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request); }

int mpi_Win_get_info(MPI_Win win, MPI_Info *info_used) { return MPI_Win_get_info(win, info_used); }

int mpi_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return MPI_File_read_at_all(fh, offset, buf, count, datatype, status); }

int mpi_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, void *comm, MPI_Status *status) { return MPI_Recv(buf, count, datatype, source, tag, comm, status); }

int mpi_Win_get_name(MPI_Win win, char *win_name, int *resultlen) { return MPI_Win_get_name(win, win_name, resultlen); }

int mpi_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype) { return MPI_File_read_at_all_begin(fh, offset, buf, count, datatype); }

int mpi_Recv_init(void *buf, int count, MPI_Datatype datatype, int source, int tag, void *comm, MPI_Request *request) { return MPI_Recv_init(buf, count, datatype, source, tag, comm, request); }

int mpi_Win_lock(int lock_type, int rank, int assert, MPI_Win win) { return MPI_Win_lock(lock_type, rank, assert, win); }

int mpi_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status) { return MPI_File_read_at_all_end(fh, buf, status); }

int mpi_Reduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, void *comm) { return MPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm); }

int mpi_Win_lock_all(int assert, MPI_Win win) { return MPI_Win_lock_all(assert, win); }

int mpi_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return MPI_File_read_ordered(fh, buf, count, datatype, status); }

int mpi_Reduce_local(const void *inbuf, void *inoutbuf, int count, MPI_Datatype datatype, MPI_Op op) { return MPI_Reduce_local(inbuf, inoutbuf, count, datatype, op); }

int mpi_Win_post(MPI_Group group, int assert, MPI_Win win) { return MPI_Win_post(group, assert, win); }

int mpi_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) { return MPI_File_read_ordered_begin(fh, buf, count, datatype); }

int mpi_Reduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], MPI_Datatype datatype, MPI_Op op, void *comm) { return MPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm); }

int mpi_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val) { return MPI_Win_set_attr(win, win_keyval, attribute_val); }

int mpi_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status) { return MPI_File_read_ordered_end(fh, buf, status); }

int mpi_Reduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, void *comm) { return MPI_Reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm); }

int mpi_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler) { return MPI_Win_set_errhandler(win, errhandler); }

int mpi_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return MPI_File_read_shared(fh, buf, count, datatype, status); }

int mpi_Register_datarep(ROMIO_CONST char *datarep, MPI_Datarep_conversion_function *read_conversion_fn, MPI_Datarep_conversion_function *write_conversion_fn, MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) { return MPI_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state); }

int mpi_Win_set_info(MPI_Win win, MPI_Info info) { return MPI_Win_set_info(win, info); }

int mpi_File_seek(MPI_File fh, MPI_Offset offset, int whence) { return MPI_File_seek(fh, offset, whence); }

int mpi_Request_free(MPI_Request *request) { return MPI_Request_free(request); }

int mpi_Win_set_name(MPI_Win win, const char *win_name) { return MPI_Win_set_name(win, win_name); }

int mpi_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence) { return MPI_File_seek_shared(fh, offset, whence); }

int mpi_Request_get_status(MPI_Request request, int *flag, MPI_Status *status) { return MPI_Request_get_status(request, flag, status); }

int mpi_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit, void *baseptr) { return MPI_Win_shared_query(win, rank, size, disp_unit, baseptr); }

int mpi_File_set_atomicity(MPI_File fh, int flag) { return MPI_File_set_atomicity(fh, flag); }

int mpi_Rget(void *origin_addr, int origin_count, MPI_Datatype
            origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win
            win, MPI_Request *request) { return MPI_Rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request); }

int mpi_Win_start(MPI_Group group, int assert, MPI_Win win) { return MPI_Win_start(group, assert, win); }

int mpi_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler) { return MPI_File_set_errhandler(file, errhandler); }

int mpi_Rget_accumulate(const void *origin_addr, int origin_count, MPI_Datatype origin_datatype, void *result_addr, int result_count, MPI_Datatype result_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request) { return MPI_Rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request); }

int mpi_Win_sync(MPI_Win win) { return MPI_Win_sync(win); }

int mpi_File_set_info(MPI_File fh, MPI_Info info) { return MPI_File_set_info(fh, info); }

int mpi_Rput(const void *origin_addr, int origin_count, MPI_Datatype
            origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win
            win, MPI_Request *request) { return MPI_Rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request); }

int mpi_Win_test(MPI_Win win, int *flag) { return MPI_Win_test(win, flag); }

int mpi_File_set_size(MPI_File fh, MPI_Offset size) { return MPI_File_set_size(fh, size); }

int mpi_Rsend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm) { return MPI_Rsend(buf, count, datatype, dest, tag, comm); }

int mpi_Win_unlock(int rank, MPI_Win win) { return MPI_Win_unlock(rank, win); }

int mpi_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, ROMIO_CONST char *datarep, MPI_Info info) { return MPI_File_set_view(fh, disp, etype, filetype, datarep, info); }

int mpi_Rsend_init(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm, MPI_Request *request) { return MPI_Rsend_init(buf, count, datatype, dest, tag, comm, request); }

int mpi_Win_unlock_all(MPI_Win win) { return MPI_Win_unlock_all(win); }

int mpi_File_sync(MPI_File fh) { return MPI_File_sync(fh); }

int mpi_Scan(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, void *comm) { return MPI_Scan(sendbuf, recvbuf, count, datatype, op, comm); }

int mpi_Win_wait(MPI_Win win) { return MPI_Win_wait(win); }

int mpi_File_write(MPI_File fh, ROMIO_CONST void *buf, int count, MPI_Datatype datatype, MPI_Status *status) { return MPI_File_write(fh, buf, count, datatype, status); }

int mpi_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, void *comm) { return MPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm); }

double mpi_Wtick() { return MPI_Wtick(); }

double mpi_Wtime() { return MPI_Wtime(); }
