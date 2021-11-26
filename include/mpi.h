#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#define MPI_MAX_ERROR_STRING 1024

typedef void *MPI_Comm;
typedef void *MPI_Datatype;
typedef void *MPI_Op;
typedef void *MPI_Request;
typedef struct {
  int MPI_SOURCE, MPI_TAG, MPI_ERROR, _a, _b, _c;
} MPI_Status;
typedef void *MPI_Group;
typedef void *MPI_File;
typedef void *MPI_Win;
typedef void *MPI_Aint;
typedef void *MPI_Offset;
typedef void *MPI_Info;
typedef void *MPI_Errhandler;
typedef void *MPIO_Request;
typedef void *MPI_Message;
typedef void *MPI_Delete_function;
typedef void *MPI_User_function;
typedef void *MPI_Comm_copy_attr_function;
typedef void *MPI_Comm_delete_attr_function;
typedef void *MPI_Comm_errhandler_function;
typedef void *MPI_Copy_function;
typedef void *MPI_Count;
typedef void *MPI_Datarep_conversion_function;
typedef void *MPI_Datarep_extent_function;
typedef void *MPI_File_errhandler_function;
typedef void *MPI_Fint;
typedef void *MPI_Grequest_cancel_function;
typedef void *MPI_Grequest_free_function;
typedef void *MPI_Grequest_query_function;
typedef void *MPI_Handler_function;
typedef void *MPI_T_cvar_handle;
typedef void *MPI_T_enum;
typedef void *MPI_T_pvar_handle;
typedef void *MPI_T_pvar_session;
typedef void *MPI_Type_copy_attr_function;
typedef void *MPI_Type_delete_attr_function;
typedef void *MPI_Win_copy_attr_function;
typedef void *MPI_Win_delete_attr_function;
typedef void *MPI_Win_errhandler_function;
extern MPI_Comm MPI_COMM_WORLD;
extern MPI_Comm MPI_COMM_NULL;
extern MPI_Comm MPI_COMM_SELF;
extern MPI_Datatype MPI_DOUBLE;
extern MPI_Datatype MPI_INT;
extern MPI_Datatype MPI_BYTE;
extern MPI_Datatype MPI_CHAR;
extern MPI_Datatype MPI_C_BOOL;
extern MPI_Datatype MPI_DOUBLE_COMPLEX;
extern MPI_Datatype *MPI_DATATYPE_NULL;
extern MPI_Datatype MPI_UNSIGNED_CHAR;
extern MPI_Datatype MPI_SHORT;
extern MPI_Datatype MPI_UNSIGNED_SHORT;
extern MPI_Datatype MPI_UNSIGNED;
extern MPI_Datatype MPI_LONG;
extern MPI_Datatype MPI_UNSIGNED_LONG;
extern MPI_Datatype MPI_FLOAT;
extern MPI_Datatype MPI_FLOAT_INT;
extern MPI_Datatype MPI_DOUBLE_INT;
extern MPI_Datatype MPI_LONG_INT;
extern MPI_Datatype MPI_SHORT_INT;
extern MPI_Datatype MPI_2INT;
extern MPI_Datatype MPI_LB;
extern MPI_Datatype MPI_UB;
extern MPI_Op MPI_MAX;
extern MPI_Op MPI_MIN;
extern MPI_Op MPI_SUM;
extern MPI_Op MPI_LOR;
extern MPI_Op MPI_BOR;
extern MPI_Op MPI_LAND;
extern MPI_Request MPI_REQUEST_NULL;
extern MPI_Group MPI_GROUP_EMPTY;
extern int MPI_SUCCESS;
extern int MPI_UNDEFINED;
extern MPI_Status *MPI_STATUS_IGNORE;
extern void *MPI_IN_PLACE;
extern int MPI_ANY_SOURCE;
extern int MPI_ANY_TAG;
extern int MPI_PROC_NULL;
extern int MPI_TAG_UB;
extern int MPI_HOST;
extern int MPI_IO;
extern int MPI_WTIME_IS_GLOBAL;
extern int MPI_UNIVERSE_SIZE;
extern int MPI_LASTUSEDCODE;
extern int MPI_APPNUM;
extern int MPI_WIN_BASE;
extern int MPI_WIN_SIZE;
extern int MPI_WIN_DISP_UNIT;
extern int MPI_WIN_CREATE_FLAVOR;
extern int MPI_WIN_MODEL;
extern MPI_Info MPI_INFO_NULL;
extern int MPI_LOCK_EXCLUSIVE;
extern int MPI_LOCK_SHARED;
extern int MPI_BSEND_OVERHEAD;
extern void *MPI_BOTTOM;
extern MPI_Datatype MPI_PACKED;

int MPI_File_write_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                       MPI_Status *status);

int MPI_Scatterv(const void *sendbuf, const int *sendcounts, const int *displs,
                 MPI_Datatype sendtype, void *recvbuf, int recvcount,
                 MPI_Datatype recvtype, int root, MPI_Comm comm);

int MPI_File_write_all_begin(MPI_File fh, void *buf, int count,
                             MPI_Datatype datatype);

int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest,
             int tag, MPI_Comm comm);

int MPI_File_write_all_end(MPI_File fh, void *buf, MPI_Status *status);

int MPI_Send_init(const void *buf, int count, MPI_Datatype datatype, int dest,
                  int tag, MPI_Comm comm, MPI_Request *request);

int MPI_Abort(MPI_Comm comm, int errorcode);

int MPI_File_write_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                      MPI_Datatype datatype, MPI_Status *status);

int MPI_Sendrecv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 int dest, int sendtag, void *recvbuf, int recvcount,
                 MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm,
                 MPI_Status *status);

int MPI_Accumulate(const void *origin_addr, int origin_count,
                   MPI_Datatype origin_datatype, int target_rank,
                   MPI_Aint target_disp, int target_count,
                   MPI_Datatype target_datatype, MPI_Op op, MPI_Win win);

int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status);

int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest,
                         int sendtag, int source, int recvtag, MPI_Comm comm,
                         MPI_Status *status);

int MPI_Add_error_class(int *errorclass);

int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf,
                                int count, MPI_Datatype datatype);

int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype, int dest,
              int tag, MPI_Comm comm);

int MPI_Add_error_code(int errorclass, int *errorcode);

int MPI_File_write_at_all_end(MPI_File fh, void *buf, MPI_Status *status);

int MPI_Ssend_init(const void *buf, int count, MPI_Datatype datatype, int dest,
                   int tag, MPI_Comm comm, MPI_Request *request);

int MPI_Add_error_string(int errorcode, const char *string);

int MPI_File_write_ordered(MPI_File fh, void *buf, int count,
                           MPI_Datatype datatype, MPI_Status *status);

int MPI_Start(MPI_Request *request);

int MPI_Address(const void *location, MPI_Aint *address);

int MPI_File_write_ordered_begin(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype);

int MPI_Startall(int count, MPI_Request array_of_requests[]);

int MPI_Allgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPI_Datatype recvtype,
                  MPI_Comm comm);

int MPI_File_write_ordered_end(MPI_File fh, void *buf, MPI_Status *status);

int MPI_Status_set_cancelled(MPI_Status *status, int flag);

int MPI_Allgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                   void *recvbuf, const int *recvcounts, const int *displs,
                   MPI_Datatype recvtype, MPI_Comm comm);

int MPI_File_write_shared(MPI_File fh, void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status);

int MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype,
                            int count);

int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr);

int MPI_Finalize();

int MPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype,
                              MPI_Count count);

int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,
                  MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

int MPI_Finalized(int *flag);

int MPI_T_category_changed(int *stamp);

int MPI_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 MPI_Comm comm);

int MPI_Free_mem(void *base);

int MPI_T_category_get_categories(int cat_index, int len, int indices[]);

int MPI_Alltoallv(const void *sendbuf, const int *sendcounts,
                  const int *sdispls, MPI_Datatype sendtype, void *recvbuf,
                  const int *recvcounts, const int *rdispls,
                  MPI_Datatype recvtype, MPI_Comm comm);

int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
               void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
               MPI_Comm comm);

int MPI_T_category_get_cvars(int cat_index, int len, int indices[]);

int MPI_Alltoallw(const void *sendbuf, const int sendcounts[],
                  const int sdispls[], const MPI_Datatype sendtypes[],
                  void *recvbuf, const int recvcounts[], const int rdispls[],
                  const MPI_Datatype recvtypes[], MPI_Comm comm);

int MPI_Gatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                void *recvbuf, const int *recvcounts, const int *displs,
                MPI_Datatype recvtype, int root, MPI_Comm comm);

int MPI_T_category_get_info(int cat_index, char *name, int *name_len,
                            char *desc, int *desc_len, int *num_cvars,
                            int *num_pvars, int *num_categories);

int MPI_Attr_delete(MPI_Comm comm, int keyval);

int MPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
            int target_rank, MPI_Aint target_disp, int target_count,
            MPI_Datatype target_datatype, MPI_Win win);

int MPI_T_category_get_num(int *num_cat);

int MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val, int *flag);

int MPI_Get_accumulate(const void *origin_addr, int origin_count,
                       MPI_Datatype origin_datatype, void *result_addr,
                       int result_count, MPI_Datatype result_datatype,
                       int target_rank, MPI_Aint target_disp, int target_count,
                       MPI_Datatype target_datatype, MPI_Op op, MPI_Win win);

int MPI_T_category_get_pvars(int cat_index, int len, int indices[]);

int MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val);

int MPI_Get_address(const void *location, MPI_Aint *address);

int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                        int *verbosity, MPI_Datatype *datatype,
                        MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *binding, int *scope);

int MPI_Barrier(MPI_Comm comm);

int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype, int *count);

int MPI_T_cvar_get_num(int *num_cvar);

int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root,
              MPI_Comm comm);

int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype,
                     int *count);

int MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                            MPI_T_cvar_handle *handle, int *count);

int MPI_Bsend(const void *buf, int count, MPI_Datatype datatype, int dest,
              int tag, MPI_Comm comm);

int MPI_Get_elements_x(const MPI_Status *status, MPI_Datatype datatype,
                       MPI_Count *count);

int MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle);

int MPI_Bsend_init(const void *buf, int count, MPI_Datatype datatype, int dest,
                   int tag, MPI_Comm comm, MPI_Request *request);

int MPI_Get_library_version(char *version, int *resultlen);

int MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf);

int MPI_Buffer_attach(void *buffer, int size);

int MPI_Get_processor_name(char *name, int *resultlen);

int MPI_T_cvar_write(MPI_T_cvar_handle handle, void *buf);

int MPI_Buffer_detach(void *buffer_addr, int *size);

int MPI_Get_version(int *version, int *subversion);

int MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name,
                        int *name_len);

int MPI_Cancel(MPI_Request *request);

int MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int indx[],
                     const int edges[], int reorder, MPI_Comm *comm_graph);

int MPI_T_enum_get_item(MPI_T_enum enumtype, int index, int *value, char *name,
                        int *name_len);

int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[]);

int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int indx[],
                  int edges[]);

int MPI_T_finalize();

int MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[],
                    const int periods[], int reorder, MPI_Comm *comm_cart);

int MPI_Graph_map(MPI_Comm comm, int nnodes, const int indx[],
                  const int edges[], int *newrank);

int MPI_T_init_thread(int required, int *provided);

int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[],
                 int coords[]);

int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors,
                        int neighbors[]);

int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                        int *verbosity, int *var_class, MPI_Datatype *datatype,
                        MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *binding, int *readonly, int *continuous,
                        int *atomic);

int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[],
                 const int periods[], int *newrank);

int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors);

int MPI_T_pvar_get_num(int *num_pvar);

int MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank);

int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges);

int MPI_T_pvar_handle_alloc(MPI_T_pvar_session session, int pvar_index,
                            void *obj_handle, MPI_T_pvar_handle *handle,
                            int *count);

int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source,
                   int *rank_dest);

int MPI_Grequest_complete(MPI_Request request);

int MPI_T_pvar_handle_free(MPI_T_pvar_session session,
                           MPI_T_pvar_handle *handle);

int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[], MPI_Comm *newcomm);

int MPI_Grequest_start(MPI_Grequest_query_function *query_fn,
                       MPI_Grequest_free_function *free_fn,
                       MPI_Grequest_cancel_function *cancel_fn,
                       void *extra_state, MPI_Request *request);

int MPI_T_pvar_read(MPI_T_pvar_session session, MPI_T_pvar_handle handle,
                    void *buf);

int MPI_Cartdim_get(MPI_Comm comm, int *ndims);

int MPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result);

int MPI_T_pvar_readreset(MPI_T_pvar_session session, MPI_T_pvar_handle handle,
                         void *buf);

int MPI_Close_port(const char *port_name);

int MPI_Group_difference(MPI_Group group1, MPI_Group group2,
                         MPI_Group *newgroup);

int MPI_T_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle);

int MPI_Comm_accept(const char *port_name, MPI_Info info, int root,
                    MPI_Comm comm, MPI_Comm *newcomm);

int MPI_Group_excl(MPI_Group group, int n, const int ranks[],
                   MPI_Group *newgroup);

int MPI_T_pvar_session_create(MPI_T_pvar_session *session);

int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode);

int MPI_Group_free(MPI_Group *group);

int MPI_T_pvar_session_free(MPI_T_pvar_session *session);

int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result);

int MPI_Group_incl(MPI_Group group, int n, const int ranks[],
                   MPI_Group *newgroup);

int MPI_T_pvar_start(MPI_T_pvar_session session, MPI_T_pvar_handle handle);

int MPI_Comm_connect(const char *port_name, MPI_Info info, int root,
                     MPI_Comm comm, MPI_Comm *newcomm);

int MPI_Group_intersection(MPI_Group group1, MPI_Group group2,
                           MPI_Group *newgroup);

int MPI_T_pvar_stop(MPI_T_pvar_session session, MPI_T_pvar_handle handle);

int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm);

int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
                         MPI_Group *newgroup);

int MPI_T_pvar_write(MPI_T_pvar_session session, MPI_T_pvar_handle handle,
                     void *buf);

int MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn,
                               MPI_Errhandler *errhandler);

int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3],
                         MPI_Group *newgroup);

int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status);

int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag,
                          MPI_Comm *newcomm);

int MPI_Group_rank(MPI_Group group, int *rank);

int MPI_Test_cancelled(const MPI_Status *status, int *flag);

int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                           MPI_Comm_delete_attr_function *comm_delete_attr_fn,
                           int *comm_keyval, void *extra_state);

int MPI_Group_size(MPI_Group group, int *size);

int MPI_Testall(int count, MPI_Request array_of_requests[], int *flag,
                MPI_Status array_of_statuses[]);

int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval);

int MPI_Group_translate_ranks(MPI_Group group1, int n, const int ranks1[],
                              MPI_Group group2, int ranks2[]);

int MPI_Testany(int count, MPI_Request array_of_requests[], int *indx,
                int *flag, MPI_Status *status);

int MPI_Comm_disconnect(MPI_Comm *comm);

int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup);

int MPI_Testsome(int incount, MPI_Request array_of_requests[], int *outcount,
                 int array_of_indices[], MPI_Status array_of_statuses[]);

int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);

int MPI_Iallgather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                   void *recvbuf, int recvcount, MPI_Datatype recvtype,
                   MPI_Comm comm, MPI_Request *request);

int MPI_Topo_test(MPI_Comm comm, int *status);

int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm);

int MPI_Iallgatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                    void *recvbuf, const int recvcounts[], const int displs[],
                    MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);

int MPI_Type_commit(MPI_Datatype *datatype);

int MPI_Comm_free(MPI_Comm *comm);

int MPI_Iallreduce(const void *sendbuf, void *recvbuf, int count,
                   MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                   MPI_Request *request);

int MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype);

int MPI_Comm_free_keyval(int *comm_keyval);

int MPI_Ialltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPI_Datatype recvtype,
                  MPI_Comm comm, MPI_Request *request);

int MPI_Type_create_darray(int size, int rank, int ndims,
                           const int array_of_gsizes[],
                           const int array_of_distribs[],
                           const int array_of_dargs[],
                           const int array_of_psizes[], int order,
                           MPI_Datatype oldtype, MPI_Datatype *newtype);

int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val,
                      int *flag);

int MPI_Ialltoallv(const void *sendbuf, const int sendcounts[],
                   const int sdispls[], MPI_Datatype sendtype, void *recvbuf,
                   const int recvcounts[], const int rdispls[],
                   MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);

int MPI_Type_create_f90_complex(int precision, int range,
                                MPI_Datatype *newtype);

int MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler);

int MPI_Ialltoallw(const void *sendbuf, const int sendcounts[],
                   const int sdispls[], const MPI_Datatype sendtypes[],
                   void *recvbuf, const int recvcounts[], const int rdispls[],
                   const MPI_Datatype recvtypes[], MPI_Comm comm,
                   MPI_Request *request);

int MPI_Type_create_f90_integer(int range, MPI_Datatype *newtype);

int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used);

int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request);

int MPI_Type_create_f90_real(int precision, int range, MPI_Datatype *newtype);

int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen);

int MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root,
               MPI_Comm comm, MPI_Request *request);

int MPI_Type_create_hindexed(int count, const int array_of_blocklengths[],
                             const MPI_Aint array_of_displacements[],
                             MPI_Datatype oldtype, MPI_Datatype *newtype);

int MPI_Comm_get_parent(MPI_Comm *parent);

int MPI_Ibsend(const void *buf, int count, MPI_Datatype datatype, int dest,
               int tag, MPI_Comm comm, MPI_Request *request);

int MPI_Type_create_hindexed_block(int count, int blocklength,
                                   const MPI_Aint array_of_displacements[],
                                   MPI_Datatype oldtype, MPI_Datatype *newtype);

int MPI_Comm_group(MPI_Comm comm, MPI_Group *group);

int MPI_Iexscan(const void *sendbuf, void *recvbuf, int count,
                MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                MPI_Request *request);

int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride,
                            MPI_Datatype oldtype, MPI_Datatype *newtype);

int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request);

int MPI_Igather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
                MPI_Comm comm, MPI_Request *request);

int MPI_Type_create_indexed_block(int count, int blocklength,
                                  const int array_of_displacements[],
                                  MPI_Datatype oldtype, MPI_Datatype *newtype);

int MPI_Comm_join(int fd, MPI_Comm *intercomm);

int MPI_Igatherv(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, const int recvcounts[], const int displs[],
                 MPI_Datatype recvtype, int root, MPI_Comm comm,
                 MPI_Request *request);

int MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn,
                           MPI_Type_delete_attr_function *type_delete_attr_fn,
                           int *type_keyval, void *extra_state);

int MPI_Comm_rank(MPI_Comm comm, int *rank);

int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag,
                MPI_Message *message, MPI_Status *status);

int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent,
                            MPI_Datatype *newtype);

int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group);

int MPI_Imrecv(void *buf, int count, MPI_Datatype datatype,
               MPI_Message *message, MPI_Request *request);

int MPI_Type_create_struct(int count, const int array_of_blocklengths[],
                           const MPI_Aint array_of_displacements[],
                           const MPI_Datatype array_of_types[],
                           MPI_Datatype *newtype);

int MPI_Comm_remote_size(MPI_Comm comm, int *size);

int MPI_Ineighbor_allgather(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf, int recvcount,
                            MPI_Datatype recvtype, MPI_Comm comm,
                            MPI_Request *request);

int MPI_Type_create_subarray(int ndims, const int array_of_sizes[],
                             const int array_of_subsizes[],
                             const int array_of_starts[], int order,
                             MPI_Datatype oldtype, MPI_Datatype *newtype);

int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val);

int MPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             const int recvcounts[], const int displs[],
                             MPI_Datatype recvtype, MPI_Comm comm,
                             MPI_Request *request);

int MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval);

int MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler);

int MPI_Ineighbor_alltoall(const void *sendbuf, int sendcount,
                           MPI_Datatype sendtype, void *recvbuf, int recvcount,
                           MPI_Datatype recvtype, MPI_Comm comm,
                           MPI_Request *request);

int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype);

int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info);

int MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                            const int sdispls[], MPI_Datatype sendtype,
                            void *recvbuf, const int recvcounts[],
                            const int rdispls[], MPI_Datatype recvtype,
                            MPI_Comm comm, MPI_Request *request);

int MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent);

int MPI_Comm_set_name(MPI_Comm comm, const char *comm_name);

int MPI_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[],
                            const MPI_Aint sdispls[],
                            const MPI_Datatype sendtypes[], void *recvbuf,
                            const int recvcounts[], const MPI_Aint rdispls[],
                            const MPI_Datatype recvtypes[], MPI_Comm comm,
                            MPI_Request *request);

int MPI_Type_free(MPI_Datatype *datatype);

int MPI_Comm_size(MPI_Comm comm, int *size);

int MPI_Info_create(MPI_Info *info);

int MPI_Type_free_keyval(int *type_keyval);

int MPI_Comm_spawn(const char *command, char *argv[], int maxprocs,
                   MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm,
                   int array_of_errcodes[]);

int MPI_Info_delete(MPI_Info info, const char *key);

int MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval,
                      void *attribute_val, int *flag);

int MPI_Comm_spawn_multiple(int count, char *array_of_commands[],
                            char **array_of_argv[],
                            const int array_of_maxprocs[],
                            const MPI_Info array_of_info[], int root,
                            MPI_Comm comm, MPI_Comm *intercomm,
                            int array_of_errcodes[]);

int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo);

int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers,
                          int max_addresses, int max_datatypes,
                          int array_of_integers[],
                          MPI_Aint array_of_addresses[],
                          MPI_Datatype array_of_datatypes[]);

int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm);

int MPI_Info_free(MPI_Info *info);

int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers,
                          int *num_addresses, int *num_datatypes,
                          int *combiner);

int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info,
                        MPI_Comm *newcomm);

int MPI_Info_get(MPI_Info info, const char *key, int valuelen, char *value,
                 int *flag);

int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent);

int MPI_Comm_test_inter(MPI_Comm comm, int *flag);

int MPI_Info_get_nkeys(MPI_Info info, int *nkeys);

int MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                          MPI_Count *extent);

int MPI_Compare_and_swap(const void *origin_addr, const void *compare_addr,
                         void *result_addr, MPI_Datatype datatype,
                         int target_rank, MPI_Aint target_disp, MPI_Win win);

int MPI_Info_get_nthkey(MPI_Info info, int n, char *key);

int MPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen);

int MPI_Dims_create(int nnodes, int ndims, int dims[]);

int MPI_Info_get_valuelen(MPI_Info info, const char *key, int *valuelen,
                          int *flag);

int MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb,
                             MPI_Aint *true_extent);

int MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[],
                          const int degrees[], const int destinations[],
                          const int weights[], MPI_Info info, int reorder,
                          MPI_Comm *comm_dist_graph);

int MPI_Info_set(MPI_Info info, const char *key, const char *value);

int MPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb,
                               MPI_Count *true_extent);

int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree,
                                   const int sources[],
                                   const int sourceweights[], int outdegree,
                                   const int destinations[],
                                   const int destweights[], MPI_Info info,
                                   int reorder, MPI_Comm *comm_dist_graph);

int MPI_Init(int *argc, char ***argv);

int MPI_Type_hindexed(int count, const int *array_of_blocklengths,
                      const MPI_Aint *array_of_displacements,
                      MPI_Datatype oldtype, MPI_Datatype *newtype);

int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[],
                             int sourceweights[], int maxoutdegree,
                             int destinations[], int destweights[]);

int MPI_Init_thread(int *argc, char ***argv, int required, int *provided);

int MPI_Type_hvector(int count, int blocklength, MPI_Aint stride,
                     MPI_Datatype oldtype, MPI_Datatype *newtype);

int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree, int *outdegree,
                                   int *weighted);

int MPI_Initialized(int *flag);

int MPI_Type_indexed(int count, const int *array_of_blocklengths,
                     const int *array_of_displacements, MPI_Datatype oldtype,
                     MPI_Datatype *newtype);

int MPI_Errhandler_create(MPI_Handler_function *function,
                          MPI_Errhandler *errhandler);

int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                         MPI_Comm peer_comm, int remote_leader, int tag,
                         MPI_Comm *newintercomm);

int MPI_Type_lb(MPI_Datatype datatype, MPI_Aint *displacement);

int MPI_Errhandler_free(MPI_Errhandler *errhandler);

int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm);

int MPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype);

int MPI_Errhandler_get(MPI_Comm comm, MPI_Errhandler *errhandler);

int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag,
               MPI_Status *status);

int MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval,
                      void *attribute_val);

int MPI_Errhandler_set(MPI_Comm comm, MPI_Errhandler errhandler);

int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag,
              MPI_Comm comm, MPI_Request *request);

int MPI_Type_set_name(MPI_Datatype datatype, const char *type_name);

int MPI_Error_class(int errorcode, int *errorclass);

int MPI_Ireduce(const void *sendbuf, void *recvbuf, int count,
                MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm,
                MPI_Request *request);

int MPI_Type_size(MPI_Datatype datatype, int *size);

int MPI_Error_string(int errorcode, char *string, int *resultlen);

int MPI_Ireduce_scatter(const void *sendbuf, void *recvbuf,
                        const int recvcounts[], MPI_Datatype datatype,
                        MPI_Op op, MPI_Comm comm, MPI_Request *request);

int MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size);

int MPI_Exscan(const void *sendbuf, void *recvbuf, int count,
               MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

int MPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount,
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                              MPI_Request *request);

int MPI_Type_struct(int count, const int *array_of_blocklengths,
                    const MPI_Aint *array_of_displacements,
                    const MPI_Datatype *array_of_types, MPI_Datatype *newtype);

int MPI_Fetch_and_op(const void *origin_addr, void *result_addr,
                     MPI_Datatype datatype, int target_rank,
                     MPI_Aint target_disp, MPI_Op op, MPI_Win win);

int MPI_Irsend(const void *buf, int count, MPI_Datatype datatype, int dest,
               int tag, MPI_Comm comm, MPI_Request *request);

int MPI_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement);

MPI_Fint MPI_File_c2f(MPI_File fh);

int MPI_Is_thread_main(int *flag);

int MPI_Type_vector(int count, int blocklength, int stride,
                    MPI_Datatype oldtype, MPI_Datatype *newtype);

int MPI_File_call_errhandler(MPI_File fh, int errorcode);

int MPI_Iscan(const void *sendbuf, void *recvbuf, int count,
              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
              MPI_Request *request);

int MPI_Unpack(const void *inbuf, int insize, int *position, void *outbuf,
               int outcount, MPI_Datatype datatype, MPI_Comm comm);

int MPI_File_close(MPI_File *fh);

int MPI_Iscatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
                 MPI_Comm comm, MPI_Request *request);

int MPI_Unpack_external(const char datarep[], const void *inbuf,
                        MPI_Aint insize, MPI_Aint *position, void *outbuf,
                        int outcount, MPI_Datatype datatype);

int MPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn,
                               MPI_Errhandler *errhandler);

int MPI_Iscatterv(const void *sendbuf, const int sendcounts[],
                  const int displs[], MPI_Datatype sendtype, void *recvbuf,
                  int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm,
                  MPI_Request *request);

int MPI_Unpublish_name(const char *service_name, MPI_Info info,
                       const char *port_name);

int MPI_File_delete(char *filename, MPI_Info info);

int MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest,
              int tag, MPI_Comm comm, MPI_Request *request);

int MPI_Wait(MPI_Request *request, MPI_Status *status);

MPI_File MPI_File_f2c(MPI_Fint fh);

int MPI_Issend(const void *buf, int count, MPI_Datatype datatype, int dest,
               int tag, MPI_Comm comm, MPI_Request *request);

int MPI_Waitall(int count, MPI_Request array_of_requests[],
                MPI_Status array_of_statuses[]);

int MPI_File_get_amode(MPI_File fh, int *amode);

int MPI_Keyval_create(MPI_Copy_function *copy_fn,
                      MPI_Delete_function *delete_fn, int *keyval,
                      void *extra_state);

int MPI_Waitany(int count, MPI_Request array_of_requests[], int *indx,
                MPI_Status *status);

int MPI_File_get_atomicity(MPI_File fh, int *flag);

int MPI_Keyval_free(int *keyval);

int MPI_Waitsome(int incount, MPI_Request array_of_requests[], int *outcount,
                 int array_of_indices[], MPI_Status array_of_statuses[]);

int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp);

int MPI_Lookup_name(const char *service_name, MPI_Info info, char *port_name);

int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm,
                     void *baseptr, MPI_Win *win);

int MPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler);

int MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message,
               MPI_Status *status);

int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info,
                            MPI_Comm comm, void *baseptr, MPI_Win *win);

int MPI_File_get_group(MPI_File fh, MPI_Group *group);

int MPI_Mrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message,
              MPI_Status *status);

int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size);

int MPI_File_get_info(MPI_File fh, MPI_Info *info_used);

int MPI_Neighbor_allgather(const void *sendbuf, int sendcount,
                           MPI_Datatype sendtype, void *recvbuf, int recvcount,
                           MPI_Datatype recvtype, MPI_Comm comm);

int MPI_Win_call_errhandler(MPI_Win win, int errorcode);

int MPI_File_get_position(MPI_File fh, MPI_Offset *offset);

int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            const int recvcounts[], const int displs[],
                            MPI_Datatype recvtype, MPI_Comm comm);

int MPI_Win_complete(MPI_Win win);

int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset);

int MPI_Neighbor_alltoall(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf, int recvcount,
                          MPI_Datatype recvtype, MPI_Comm comm);

int MPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info,
                   MPI_Comm comm, MPI_Win *win);

int MPI_File_get_size(MPI_File fh, MPI_Offset *size);

int MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                           const int sdispls[], MPI_Datatype sendtype,
                           void *recvbuf, const int recvcounts[],
                           const int rdispls[], MPI_Datatype recvtype,
                           MPI_Comm comm);

int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win);

int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype,
                             MPI_Aint *extent);

int MPI_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[],
                           const MPI_Aint sdispls[],
                           const MPI_Datatype sendtypes[], void *recvbuf,
                           const int recvcounts[], const MPI_Aint rdispls[],
                           const MPI_Datatype recvtypes[], MPI_Comm comm);

int MPI_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn,
                              MPI_Errhandler *errhandler);

int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype,
                      MPI_Datatype *filetype, char *datarep);

int MPI_Op_commutative(MPI_Op op, int *commute);

int MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn,
                          MPI_Win_delete_attr_function *win_delete_attr_fn,
                          int *win_keyval, void *extra_state);

int MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                   MPI_Request *request);

int MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op);

int MPI_Win_delete_attr(MPI_Win win, int win_keyval);

int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                      MPI_Datatype datatype, MPIO_Request *request);

int MPI_Op_free(MPI_Op *op);

int MPI_Win_detach(MPI_Win win, const void *base);

int MPI_File_iread_shared(MPI_File fh, void *buf, int count,
                          MPI_Datatype datatype, MPI_Request *request);

int MPI_Open_port(MPI_Info info, char *port_name);

int MPI_Win_fence(int assert, MPI_Win win);

int MPI_File_iwrite(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                    MPI_Request *request);

int MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype,
             void *outbuf, int outsize, int *position, MPI_Comm comm);

int MPI_Win_flush(int rank, MPI_Win win);

int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                       MPI_Datatype datatype, MPIO_Request *request);

int MPI_Pack_external(const char datarep[], const void *inbuf, int incount,
                      MPI_Datatype datatype, void *outbuf, MPI_Aint outsize,
                      MPI_Aint *position);

int MPI_Win_flush_all(MPI_Win win);

int MPI_File_iwrite_shared(MPI_File fh, void *buf, int count,
                           MPI_Datatype datatype, MPIO_Request *request);

int MPI_Pack_external_size(const char datarep[], int incount,
                           MPI_Datatype datatype, MPI_Aint *size);

int MPI_Win_flush_local(int rank, MPI_Win win);

int MPI_File_open(MPI_Comm comm, char *filename, int amode, MPI_Info info,
                  MPI_File *fh);

int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm, int *size);

int MPI_Win_flush_local_all(MPI_Win win);

int MPI_File_preallocate(MPI_File fh, MPI_Offset size);

int MPI_Win_free(MPI_Win *win);

int MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                  MPI_Status *status);

int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status);

int MPI_Win_free_keyval(int *win_keyval);

int MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                      MPI_Status *status);

int MPI_Publish_name(const char *service_name, MPI_Info info,
                     const char *port_name);

int MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val,
                     int *flag);

int MPI_File_read_all_begin(MPI_File fh, void *buf, int count,
                            MPI_Datatype datatype);

int MPI_Put(const void *origin_addr, int origin_count,
            MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp,
            int target_count, MPI_Datatype target_datatype, MPI_Win win);

int MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler);

int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status);

int MPI_Query_thread(int *provided);

int MPI_Win_get_group(MPI_Win win, MPI_Group *group);

int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                     MPI_Datatype datatype, MPI_Status *status);

int MPI_Raccumulate(const void *origin_addr, int origin_count,
                    MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count,
                    MPI_Datatype target_datatype, MPI_Op op, MPI_Win win,
                    MPI_Request *request);

int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used);

int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status);

int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag,
             MPI_Comm comm, MPI_Status *status);

int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen);

int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf,
                               int count, MPI_Datatype datatype);

int MPI_Recv_init(void *buf, int count, MPI_Datatype datatype, int source,
                  int tag, MPI_Comm comm, MPI_Request *request);

int MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win);

int MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status);

int MPI_Reduce(const void *sendbuf, void *recvbuf, int count,
               MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm);

int MPI_Win_lock_all(int assert, MPI_Win win);

int MPI_File_read_ordered(MPI_File fh, void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status);

int MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count,
                     MPI_Datatype datatype, MPI_Op op);

int MPI_Win_post(MPI_Group group, int assert, MPI_Win win);

int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count,
                                MPI_Datatype datatype);

int MPI_Reduce_scatter(const void *sendbuf, void *recvbuf,
                       const int recvcounts[], MPI_Datatype datatype, MPI_Op op,
                       MPI_Comm comm);

int MPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val);

int MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status);

int MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount,
                             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

int MPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler);

int MPI_File_read_shared(MPI_File fh, void *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status);

int MPI_Register_datarep(char *datarep,
                         MPI_Datarep_conversion_function *read_conversion_fn,
                         MPI_Datarep_conversion_function *write_conversion_fn,
                         MPI_Datarep_extent_function *dtype_file_extent_fn,
                         void *extra_state);

int MPI_Win_set_info(MPI_Win win, MPI_Info info);

int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence);

int MPI_Request_free(MPI_Request *request);

int MPI_Win_set_name(MPI_Win win, const char *win_name);

int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence);

int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status);

int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit,
                         void *baseptr);

int MPI_File_set_atomicity(MPI_File fh, int flag);

int MPI_Rget(void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
             int target_rank, MPI_Aint target_disp, int target_count,
             MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request);

int MPI_Win_start(MPI_Group group, int assert, MPI_Win win);

int MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler);

int MPI_Rget_accumulate(const void *origin_addr, int origin_count,
                        MPI_Datatype origin_datatype, void *result_addr,
                        int result_count, MPI_Datatype result_datatype,
                        int target_rank, MPI_Aint target_disp, int target_count,
                        MPI_Datatype target_datatype, MPI_Op op, MPI_Win win,
                        MPI_Request *request);

int MPI_Win_sync(MPI_Win win);

int MPI_File_set_info(MPI_File fh, MPI_Info info);

int MPI_Rput(const void *origin_addr, int origin_count,
             MPI_Datatype origin_datatype, int target_rank,
             MPI_Aint target_disp, int target_count,
             MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request);

int MPI_Win_test(MPI_Win win, int *flag);

int MPI_File_set_size(MPI_File fh, MPI_Offset size);

int MPI_Rsend(const void *buf, int count, MPI_Datatype datatype, int dest,
              int tag, MPI_Comm comm);

int MPI_Win_unlock(int rank, MPI_Win win);

int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype,
                      MPI_Datatype filetype, char *datarep, MPI_Info info);

int MPI_Rsend_init(const void *buf, int count, MPI_Datatype datatype, int dest,
                   int tag, MPI_Comm comm, MPI_Request *request);

int MPI_Win_unlock_all(MPI_Win win);

int MPI_File_sync(MPI_File fh);

int MPI_Scan(const void *sendbuf, void *recvbuf, int count,
             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

int MPI_Win_wait(MPI_Win win);

int MPI_File_write(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                   MPI_Status *status);

int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
                MPI_Comm comm);

double MPI_Wtick();

double MPI_Wtime();

#ifdef __cplusplus
}
#endif
