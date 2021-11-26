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

int multimpi_MPI_File_write_all(MPI_File fh, void *buf, int count,
                                MPI_Datatype datatype, MPI_Status *status);
static inline int MPI_File_write_all(MPI_File fh, void *buf, int count,
                                     MPI_Datatype datatype,
                                     MPI_Status *status) {
  return multimpi_MPI_File_write_all(fh, buf, count, datatype, status);
}

int multimpi_MPI_Scatterv(const void *sendbuf, const int *sendcounts,
                          const int *displs, MPI_Datatype sendtype,
                          void *recvbuf, int recvcount, MPI_Datatype recvtype,
                          int root, MPI_Comm comm);
static inline int MPI_Scatterv(const void *sendbuf, const int *sendcounts,
                               const int *displs, MPI_Datatype sendtype,
                               void *recvbuf, int recvcount,
                               MPI_Datatype recvtype, int root, MPI_Comm comm) {
  return multimpi_MPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf,
                               recvcount, recvtype, root, comm);
}

int multimpi_MPI_File_write_all_begin(MPI_File fh, void *buf, int count,
                                      MPI_Datatype datatype);
static inline int MPI_File_write_all_begin(MPI_File fh, void *buf, int count,
                                           MPI_Datatype datatype) {
  return multimpi_MPI_File_write_all_begin(fh, buf, count, datatype);
}

int multimpi_MPI_Send(const void *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm);
static inline int MPI_Send(const void *buf, int count, MPI_Datatype datatype,
                           int dest, int tag, MPI_Comm comm) {
  return multimpi_MPI_Send(buf, count, datatype, dest, tag, comm);
}

int multimpi_MPI_File_write_all_end(MPI_File fh, void *buf, MPI_Status *status);
static inline int MPI_File_write_all_end(MPI_File fh, void *buf,
                                         MPI_Status *status) {
  return multimpi_MPI_File_write_all_end(fh, buf, status);
}

int multimpi_MPI_Send_init(const void *buf, int count, MPI_Datatype datatype,
                           int dest, int tag, MPI_Comm comm,
                           MPI_Request *request);
static inline int MPI_Send_init(const void *buf, int count,
                                MPI_Datatype datatype, int dest, int tag,
                                MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Send_init(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Abort(MPI_Comm comm, int errorcode);
static inline int MPI_Abort(MPI_Comm comm, int errorcode) {
  return multimpi_MPI_Abort(comm, errorcode);
}

int multimpi_MPI_File_write_at(MPI_File fh, MPI_Offset offset, void *buf,
                               int count, MPI_Datatype datatype,
                               MPI_Status *status);
static inline int MPI_File_write_at(MPI_File fh, MPI_Offset offset, void *buf,
                                    int count, MPI_Datatype datatype,
                                    MPI_Status *status) {
  return multimpi_MPI_File_write_at(fh, offset, buf, count, datatype, status);
}

int multimpi_MPI_Sendrecv(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, int dest, int sendtag,
                          void *recvbuf, int recvcount, MPI_Datatype recvtype,
                          int source, int recvtag, MPI_Comm comm,
                          MPI_Status *status);
static inline int MPI_Sendrecv(const void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, int dest, int sendtag,
                               void *recvbuf, int recvcount,
                               MPI_Datatype recvtype, int source, int recvtag,
                               MPI_Comm comm, MPI_Status *status) {
  return multimpi_MPI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag,
                               recvbuf, recvcount, recvtype, source, recvtag,
                               comm, status);
}

int multimpi_MPI_Accumulate(const void *origin_addr, int origin_count,
                            MPI_Datatype origin_datatype, int target_rank,
                            MPI_Aint target_disp, int target_count,
                            MPI_Datatype target_datatype, MPI_Op op,
                            MPI_Win win);
static inline int MPI_Accumulate(const void *origin_addr, int origin_count,
                                 MPI_Datatype origin_datatype, int target_rank,
                                 MPI_Aint target_disp, int target_count,
                                 MPI_Datatype target_datatype, MPI_Op op,
                                 MPI_Win win) {
  return multimpi_MPI_Accumulate(origin_addr, origin_count, origin_datatype,
                                 target_rank, target_disp, target_count,
                                 target_datatype, op, win);
}

int multimpi_MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, void *buf,
                                   int count, MPI_Datatype datatype,
                                   MPI_Status *status);
static inline int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset,
                                        void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Status *status) {
  return multimpi_MPI_File_write_at_all(fh, offset, buf, count, datatype,
                                        status);
}

int multimpi_MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype,
                                  int dest, int sendtag, int source,
                                  int recvtag, MPI_Comm comm,
                                  MPI_Status *status);
static inline int MPI_Sendrecv_replace(void *buf, int count,
                                       MPI_Datatype datatype, int dest,
                                       int sendtag, int source, int recvtag,
                                       MPI_Comm comm, MPI_Status *status) {
  return multimpi_MPI_Sendrecv_replace(buf, count, datatype, dest, sendtag,
                                       source, recvtag, comm, status);
}

int multimpi_MPI_Add_error_class(int *errorclass);
static inline int MPI_Add_error_class(int *errorclass) {
  return multimpi_MPI_Add_error_class(errorclass);
}

int multimpi_MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset,
                                         void *buf, int count,
                                         MPI_Datatype datatype);
static inline int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset,
                                              void *buf, int count,
                                              MPI_Datatype datatype) {
  return multimpi_MPI_File_write_at_all_begin(fh, offset, buf, count, datatype);
}

int multimpi_MPI_Ssend(const void *buf, int count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm);
static inline int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm) {
  return multimpi_MPI_Ssend(buf, count, datatype, dest, tag, comm);
}

int multimpi_MPI_Add_error_code(int errorclass, int *errorcode);
static inline int MPI_Add_error_code(int errorclass, int *errorcode) {
  return multimpi_MPI_Add_error_code(errorclass, errorcode);
}

int multimpi_MPI_File_write_at_all_end(MPI_File fh, void *buf,
                                       MPI_Status *status);
static inline int MPI_File_write_at_all_end(MPI_File fh, void *buf,
                                            MPI_Status *status) {
  return multimpi_MPI_File_write_at_all_end(fh, buf, status);
}

int multimpi_MPI_Ssend_init(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm,
                            MPI_Request *request);
static inline int MPI_Ssend_init(const void *buf, int count,
                                 MPI_Datatype datatype, int dest, int tag,
                                 MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Ssend_init(buf, count, datatype, dest, tag, comm,
                                 request);
}

int multimpi_MPI_Add_error_string(int errorcode, const char *string);
static inline int MPI_Add_error_string(int errorcode, const char *string) {
  return multimpi_MPI_Add_error_string(errorcode, string);
}

int multimpi_MPI_File_write_ordered(MPI_File fh, void *buf, int count,
                                    MPI_Datatype datatype, MPI_Status *status);
static inline int MPI_File_write_ordered(MPI_File fh, void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Status *status) {
  return multimpi_MPI_File_write_ordered(fh, buf, count, datatype, status);
}

int multimpi_MPI_Start(MPI_Request *request);
static inline int MPI_Start(MPI_Request *request) {
  return multimpi_MPI_Start(request);
}

int multimpi_MPI_Address(const void *location, MPI_Aint *address);
static inline int MPI_Address(const void *location, MPI_Aint *address) {
  return multimpi_MPI_Address(location, address);
}

int multimpi_MPI_File_write_ordered_begin(MPI_File fh, void *buf, int count,
                                          MPI_Datatype datatype);
static inline int MPI_File_write_ordered_begin(MPI_File fh, void *buf,
                                               int count,
                                               MPI_Datatype datatype) {
  return multimpi_MPI_File_write_ordered_begin(fh, buf, count, datatype);
}

int multimpi_MPI_Startall(int count, MPI_Request array_of_requests[]);
static inline int MPI_Startall(int count, MPI_Request array_of_requests[]) {
  return multimpi_MPI_Startall(count, array_of_requests);
}

int multimpi_MPI_Allgather(const void *sendbuf, int sendcount,
                           MPI_Datatype sendtype, void *recvbuf, int recvcount,
                           MPI_Datatype recvtype, MPI_Comm comm);
static inline int MPI_Allgather(const void *sendbuf, int sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                int recvcount, MPI_Datatype recvtype,
                                MPI_Comm comm) {
  return multimpi_MPI_Allgather(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm);
}

int multimpi_MPI_File_write_ordered_end(MPI_File fh, void *buf,
                                        MPI_Status *status);
static inline int MPI_File_write_ordered_end(MPI_File fh, void *buf,
                                             MPI_Status *status) {
  return multimpi_MPI_File_write_ordered_end(fh, buf, status);
}

int multimpi_MPI_Status_set_cancelled(MPI_Status *status, int flag);
static inline int MPI_Status_set_cancelled(MPI_Status *status, int flag) {
  return multimpi_MPI_Status_set_cancelled(status, flag);
}

int multimpi_MPI_Allgatherv(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            const int *recvcounts, const int *displs,
                            MPI_Datatype recvtype, MPI_Comm comm);
static inline int MPI_Allgatherv(const void *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 const int *recvcounts, const int *displs,
                                 MPI_Datatype recvtype, MPI_Comm comm) {
  return multimpi_MPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcounts, displs, recvtype, comm);
}

int multimpi_MPI_File_write_shared(MPI_File fh, void *buf, int count,
                                   MPI_Datatype datatype, MPI_Status *status);
static inline int MPI_File_write_shared(MPI_File fh, void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Status *status) {
  return multimpi_MPI_File_write_shared(fh, buf, count, datatype, status);
}

int multimpi_MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype,
                                     int count);
static inline int MPI_Status_set_elements(MPI_Status *status,
                                          MPI_Datatype datatype, int count) {
  return multimpi_MPI_Status_set_elements(status, datatype, count);
}

int multimpi_MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr);
static inline int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr) {
  return multimpi_MPI_Alloc_mem(size, info, baseptr);
}

int multimpi_MPI_Finalize();
static inline int MPI_Finalize() { return multimpi_MPI_Finalize(); }

int multimpi_MPI_Status_set_elements_x(MPI_Status *status,
                                       MPI_Datatype datatype, MPI_Count count);
static inline int MPI_Status_set_elements_x(MPI_Status *status,
                                            MPI_Datatype datatype,
                                            MPI_Count count) {
  return multimpi_MPI_Status_set_elements_x(status, datatype, count);
}

int multimpi_MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,
                           MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
static inline int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,
                                MPI_Datatype datatype, MPI_Op op,
                                MPI_Comm comm) {
  return multimpi_MPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm);
}

int multimpi_MPI_Finalized(int *flag);
static inline int MPI_Finalized(int *flag) {
  return multimpi_MPI_Finalized(flag);
}

int multimpi_MPI_T_category_changed(int *stamp);
static inline int MPI_T_category_changed(int *stamp) {
  return multimpi_MPI_T_category_changed(stamp);
}

int multimpi_MPI_Alltoall(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf, int recvcount,
                          MPI_Datatype recvtype, MPI_Comm comm);
static inline int MPI_Alltoall(const void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               int recvcount, MPI_Datatype recvtype,
                               MPI_Comm comm) {
  return multimpi_MPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                               recvtype, comm);
}

int multimpi_MPI_Free_mem(void *base);
static inline int MPI_Free_mem(void *base) {
  return multimpi_MPI_Free_mem(base);
}

int multimpi_MPI_T_category_get_categories(int cat_index, int len,
                                           int indices[]);
static inline int MPI_T_category_get_categories(int cat_index, int len,
                                                int indices[]) {
  return multimpi_MPI_T_category_get_categories(cat_index, len, indices);
}

int multimpi_MPI_Alltoallv(const void *sendbuf, const int *sendcounts,
                           const int *sdispls, MPI_Datatype sendtype,
                           void *recvbuf, const int *recvcounts,
                           const int *rdispls, MPI_Datatype recvtype,
                           MPI_Comm comm);
static inline int MPI_Alltoallv(const void *sendbuf, const int *sendcounts,
                                const int *sdispls, MPI_Datatype sendtype,
                                void *recvbuf, const int *recvcounts,
                                const int *rdispls, MPI_Datatype recvtype,
                                MPI_Comm comm) {
  return multimpi_MPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                recvcounts, rdispls, recvtype, comm);
}

int multimpi_MPI_Gather(const void *sendbuf, int sendcount,
                        MPI_Datatype sendtype, void *recvbuf, int recvcount,
                        MPI_Datatype recvtype, int root, MPI_Comm comm);
static inline int MPI_Gather(const void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             int recvcount, MPI_Datatype recvtype, int root,
                             MPI_Comm comm) {
  return multimpi_MPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                             recvtype, root, comm);
}

int multimpi_MPI_T_category_get_cvars(int cat_index, int len, int indices[]);
static inline int MPI_T_category_get_cvars(int cat_index, int len,
                                           int indices[]) {
  return multimpi_MPI_T_category_get_cvars(cat_index, len, indices);
}

int multimpi_MPI_Alltoallw(const void *sendbuf, const int sendcounts[],
                           const int sdispls[], const MPI_Datatype sendtypes[],
                           void *recvbuf, const int recvcounts[],
                           const int rdispls[], const MPI_Datatype recvtypes[],
                           MPI_Comm comm);
static inline int MPI_Alltoallw(const void *sendbuf, const int sendcounts[],
                                const int sdispls[],
                                const MPI_Datatype sendtypes[], void *recvbuf,
                                const int recvcounts[], const int rdispls[],
                                const MPI_Datatype recvtypes[], MPI_Comm comm) {
  return multimpi_MPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes,
                                recvbuf, recvcounts, rdispls, recvtypes, comm);
}

int multimpi_MPI_Gatherv(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, void *recvbuf,
                         const int *recvcounts, const int *displs,
                         MPI_Datatype recvtype, int root, MPI_Comm comm);
static inline int MPI_Gatherv(const void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              const int *recvcounts, const int *displs,
                              MPI_Datatype recvtype, int root, MPI_Comm comm) {
  return multimpi_MPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                              displs, recvtype, root, comm);
}

int multimpi_MPI_T_category_get_info(int cat_index, char *name, int *name_len,
                                     char *desc, int *desc_len, int *num_cvars,
                                     int *num_pvars, int *num_categories);
static inline int MPI_T_category_get_info(int cat_index, char *name,
                                          int *name_len, char *desc,
                                          int *desc_len, int *num_cvars,
                                          int *num_pvars, int *num_categories) {
  return multimpi_MPI_T_category_get_info(cat_index, name, name_len, desc,
                                          desc_len, num_cvars, num_pvars,
                                          num_categories);
}

int multimpi_MPI_Attr_delete(MPI_Comm comm, int keyval);
static inline int MPI_Attr_delete(MPI_Comm comm, int keyval) {
  return multimpi_MPI_Attr_delete(comm, keyval);
}

int multimpi_MPI_Get(void *origin_addr, int origin_count,
                     MPI_Datatype origin_datatype, int target_rank,
                     MPI_Aint target_disp, int target_count,
                     MPI_Datatype target_datatype, MPI_Win win);
static inline int MPI_Get(void *origin_addr, int origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, int target_count,
                          MPI_Datatype target_datatype, MPI_Win win) {
  return multimpi_MPI_Get(origin_addr, origin_count, origin_datatype,
                          target_rank, target_disp, target_count,
                          target_datatype, win);
}

int multimpi_MPI_T_category_get_num(int *num_cat);
static inline int MPI_T_category_get_num(int *num_cat) {
  return multimpi_MPI_T_category_get_num(num_cat);
}

int multimpi_MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val,
                          int *flag);
static inline int MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val,
                               int *flag) {
  return multimpi_MPI_Attr_get(comm, keyval, attribute_val, flag);
}

int multimpi_MPI_Get_accumulate(const void *origin_addr, int origin_count,
                                MPI_Datatype origin_datatype, void *result_addr,
                                int result_count, MPI_Datatype result_datatype,
                                int target_rank, MPI_Aint target_disp,
                                int target_count, MPI_Datatype target_datatype,
                                MPI_Op op, MPI_Win win);
static inline int
MPI_Get_accumulate(const void *origin_addr, int origin_count,
                   MPI_Datatype origin_datatype, void *result_addr,
                   int result_count, MPI_Datatype result_datatype,
                   int target_rank, MPI_Aint target_disp, int target_count,
                   MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) {
  return multimpi_MPI_Get_accumulate(origin_addr, origin_count, origin_datatype,
                                     result_addr, result_count, result_datatype,
                                     target_rank, target_disp, target_count,
                                     target_datatype, op, win);
}

int multimpi_MPI_T_category_get_pvars(int cat_index, int len, int indices[]);
static inline int MPI_T_category_get_pvars(int cat_index, int len,
                                           int indices[]) {
  return multimpi_MPI_T_category_get_pvars(cat_index, len, indices);
}

int multimpi_MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val);
static inline int MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val) {
  return multimpi_MPI_Attr_put(comm, keyval, attribute_val);
}

int multimpi_MPI_Get_address(const void *location, MPI_Aint *address);
static inline int MPI_Get_address(const void *location, MPI_Aint *address) {
  return multimpi_MPI_Get_address(location, address);
}

int multimpi_MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                                 int *verbosity, MPI_Datatype *datatype,
                                 MPI_T_enum *enumtype, char *desc,
                                 int *desc_len, int *binding, int *scope);
static inline int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                                      int *verbosity, MPI_Datatype *datatype,
                                      MPI_T_enum *enumtype, char *desc,
                                      int *desc_len, int *binding, int *scope) {
  return multimpi_MPI_T_cvar_get_info(cvar_index, name, name_len, verbosity,
                                      datatype, enumtype, desc, desc_len,
                                      binding, scope);
}

int multimpi_MPI_Barrier(MPI_Comm comm);
static inline int MPI_Barrier(MPI_Comm comm) {
  return multimpi_MPI_Barrier(comm);
}

int multimpi_MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype,
                           int *count);
static inline int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype,
                                int *count) {
  return multimpi_MPI_Get_count(status, datatype, count);
}

int multimpi_MPI_T_cvar_get_num(int *num_cvar);
static inline int MPI_T_cvar_get_num(int *num_cvar) {
  return multimpi_MPI_T_cvar_get_num(num_cvar);
}

int multimpi_MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root,
                       MPI_Comm comm);
static inline int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype,
                            int root, MPI_Comm comm) {
  return multimpi_MPI_Bcast(buffer, count, datatype, root, comm);
}

int multimpi_MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype,
                              int *count);
static inline int MPI_Get_elements(const MPI_Status *status,
                                   MPI_Datatype datatype, int *count) {
  return multimpi_MPI_Get_elements(status, datatype, count);
}

int multimpi_MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                                     MPI_T_cvar_handle *handle, int *count);
static inline int MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                                          MPI_T_cvar_handle *handle,
                                          int *count) {
  return multimpi_MPI_T_cvar_handle_alloc(cvar_index, obj_handle, handle,
                                          count);
}

int multimpi_MPI_Bsend(const void *buf, int count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm);
static inline int MPI_Bsend(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm) {
  return multimpi_MPI_Bsend(buf, count, datatype, dest, tag, comm);
}

int multimpi_MPI_Get_elements_x(const MPI_Status *status, MPI_Datatype datatype,
                                MPI_Count *count);
static inline int MPI_Get_elements_x(const MPI_Status *status,
                                     MPI_Datatype datatype, MPI_Count *count) {
  return multimpi_MPI_Get_elements_x(status, datatype, count);
}

int multimpi_MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle);
static inline int MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle) {
  return multimpi_MPI_T_cvar_handle_free(handle);
}

int multimpi_MPI_Bsend_init(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm,
                            MPI_Request *request);
static inline int MPI_Bsend_init(const void *buf, int count,
                                 MPI_Datatype datatype, int dest, int tag,
                                 MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Bsend_init(buf, count, datatype, dest, tag, comm,
                                 request);
}

int multimpi_MPI_Get_library_version(char *version, int *resultlen);
static inline int MPI_Get_library_version(char *version, int *resultlen) {
  return multimpi_MPI_Get_library_version(version, resultlen);
}

int multimpi_MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf);
static inline int MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf) {
  return multimpi_MPI_T_cvar_read(handle, buf);
}

int multimpi_MPI_Buffer_attach(void *buffer, int size);
static inline int MPI_Buffer_attach(void *buffer, int size) {
  return multimpi_MPI_Buffer_attach(buffer, size);
}

int multimpi_MPI_Get_processor_name(char *name, int *resultlen);
static inline int MPI_Get_processor_name(char *name, int *resultlen) {
  return multimpi_MPI_Get_processor_name(name, resultlen);
}

int multimpi_MPI_T_cvar_write(MPI_T_cvar_handle handle, void *buf);
static inline int MPI_T_cvar_write(MPI_T_cvar_handle handle, void *buf) {
  return multimpi_MPI_T_cvar_write(handle, buf);
}

int multimpi_MPI_Buffer_detach(void *buffer_addr, int *size);
static inline int MPI_Buffer_detach(void *buffer_addr, int *size) {
  return multimpi_MPI_Buffer_detach(buffer_addr, size);
}

int multimpi_MPI_Get_version(int *version, int *subversion);
static inline int MPI_Get_version(int *version, int *subversion) {
  return multimpi_MPI_Get_version(version, subversion);
}

int multimpi_MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name,
                                 int *name_len);
static inline int MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name,
                                      int *name_len) {
  return multimpi_MPI_T_enum_get_info(enumtype, num, name, name_len);
}

int multimpi_MPI_Cancel(MPI_Request *request);
static inline int MPI_Cancel(MPI_Request *request) {
  return multimpi_MPI_Cancel(request);
}

int multimpi_MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int indx[],
                              const int edges[], int reorder,
                              MPI_Comm *comm_graph);
static inline int MPI_Graph_create(MPI_Comm comm_old, int nnodes,
                                   const int indx[], const int edges[],
                                   int reorder, MPI_Comm *comm_graph) {
  return multimpi_MPI_Graph_create(comm_old, nnodes, indx, edges, reorder,
                                   comm_graph);
}

int multimpi_MPI_T_enum_get_item(MPI_T_enum enumtype, int index, int *value,
                                 char *name, int *name_len);
static inline int MPI_T_enum_get_item(MPI_T_enum enumtype, int index,
                                      int *value, char *name, int *name_len) {
  return multimpi_MPI_T_enum_get_item(enumtype, index, value, name, name_len);
}

int multimpi_MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims,
                             int coords[]);
static inline int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims,
                                  int coords[]) {
  return multimpi_MPI_Cart_coords(comm, rank, maxdims, coords);
}

int multimpi_MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges,
                           int indx[], int edges[]);
static inline int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges,
                                int indx[], int edges[]) {
  return multimpi_MPI_Graph_get(comm, maxindex, maxedges, indx, edges);
}

int multimpi_MPI_T_finalize();
static inline int MPI_T_finalize() { return multimpi_MPI_T_finalize(); }

int multimpi_MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[],
                             const int periods[], int reorder,
                             MPI_Comm *comm_cart);
static inline int MPI_Cart_create(MPI_Comm comm_old, int ndims,
                                  const int dims[], const int periods[],
                                  int reorder, MPI_Comm *comm_cart) {
  return multimpi_MPI_Cart_create(comm_old, ndims, dims, periods, reorder,
                                  comm_cart);
}

int multimpi_MPI_Graph_map(MPI_Comm comm, int nnodes, const int indx[],
                           const int edges[], int *newrank);
static inline int MPI_Graph_map(MPI_Comm comm, int nnodes, const int indx[],
                                const int edges[], int *newrank) {
  return multimpi_MPI_Graph_map(comm, nnodes, indx, edges, newrank);
}

int multimpi_MPI_T_init_thread(int required, int *provided);
static inline int MPI_T_init_thread(int required, int *provided) {
  return multimpi_MPI_T_init_thread(required, provided);
}

int multimpi_MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[],
                          int coords[]);
static inline int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[],
                               int periods[], int coords[]) {
  return multimpi_MPI_Cart_get(comm, maxdims, dims, periods, coords);
}

int multimpi_MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors,
                                 int neighbors[]);
static inline int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors,
                                      int neighbors[]) {
  return multimpi_MPI_Graph_neighbors(comm, rank, maxneighbors, neighbors);
}

int multimpi_MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                                 int *verbosity, int *var_class,
                                 MPI_Datatype *datatype, MPI_T_enum *enumtype,
                                 char *desc, int *desc_len, int *binding,
                                 int *readonly, int *continuous, int *atomic);
static inline int
MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity,
                    int *var_class, MPI_Datatype *datatype,
                    MPI_T_enum *enumtype, char *desc, int *desc_len,
                    int *binding, int *readonly, int *continuous, int *atomic) {
  return multimpi_MPI_T_pvar_get_info(
      pvar_index, name, name_len, verbosity, var_class, datatype, enumtype,
      desc, desc_len, binding, readonly, continuous, atomic);
}

int multimpi_MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[],
                          const int periods[], int *newrank);
static inline int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[],
                               const int periods[], int *newrank) {
  return multimpi_MPI_Cart_map(comm, ndims, dims, periods, newrank);
}

int multimpi_MPI_Graph_neighbors_count(MPI_Comm comm, int rank,
                                       int *nneighbors);
static inline int MPI_Graph_neighbors_count(MPI_Comm comm, int rank,
                                            int *nneighbors) {
  return multimpi_MPI_Graph_neighbors_count(comm, rank, nneighbors);
}

int multimpi_MPI_T_pvar_get_num(int *num_pvar);
static inline int MPI_T_pvar_get_num(int *num_pvar) {
  return multimpi_MPI_T_pvar_get_num(num_pvar);
}

int multimpi_MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank);
static inline int MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank) {
  return multimpi_MPI_Cart_rank(comm, coords, rank);
}

int multimpi_MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges);
static inline int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges) {
  return multimpi_MPI_Graphdims_get(comm, nnodes, nedges);
}

int multimpi_MPI_T_pvar_handle_alloc(MPI_T_pvar_session session, int pvar_index,
                                     void *obj_handle,
                                     MPI_T_pvar_handle *handle, int *count);
static inline int MPI_T_pvar_handle_alloc(MPI_T_pvar_session session,
                                          int pvar_index, void *obj_handle,
                                          MPI_T_pvar_handle *handle,
                                          int *count) {
  return multimpi_MPI_T_pvar_handle_alloc(session, pvar_index, obj_handle,
                                          handle, count);
}

int multimpi_MPI_Cart_shift(MPI_Comm comm, int direction, int disp,
                            int *rank_source, int *rank_dest);
static inline int MPI_Cart_shift(MPI_Comm comm, int direction, int disp,
                                 int *rank_source, int *rank_dest) {
  return multimpi_MPI_Cart_shift(comm, direction, disp, rank_source, rank_dest);
}

int multimpi_MPI_Grequest_complete(MPI_Request request);
static inline int MPI_Grequest_complete(MPI_Request request) {
  return multimpi_MPI_Grequest_complete(request);
}

int multimpi_MPI_T_pvar_handle_free(MPI_T_pvar_session session,
                                    MPI_T_pvar_handle *handle);
static inline int MPI_T_pvar_handle_free(MPI_T_pvar_session session,
                                         MPI_T_pvar_handle *handle) {
  return multimpi_MPI_T_pvar_handle_free(session, handle);
}

int multimpi_MPI_Cart_sub(MPI_Comm comm, const int remain_dims[],
                          MPI_Comm *newcomm);
static inline int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[],
                               MPI_Comm *newcomm) {
  return multimpi_MPI_Cart_sub(comm, remain_dims, newcomm);
}

int multimpi_MPI_Grequest_start(MPI_Grequest_query_function *query_fn,
                                MPI_Grequest_free_function *free_fn,
                                MPI_Grequest_cancel_function *cancel_fn,
                                void *extra_state, MPI_Request *request);
static inline int MPI_Grequest_start(MPI_Grequest_query_function *query_fn,
                                     MPI_Grequest_free_function *free_fn,
                                     MPI_Grequest_cancel_function *cancel_fn,
                                     void *extra_state, MPI_Request *request) {
  return multimpi_MPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state,
                                     request);
}

int multimpi_MPI_T_pvar_read(MPI_T_pvar_session session,
                             MPI_T_pvar_handle handle, void *buf);
static inline int MPI_T_pvar_read(MPI_T_pvar_session session,
                                  MPI_T_pvar_handle handle, void *buf) {
  return multimpi_MPI_T_pvar_read(session, handle, buf);
}

int multimpi_MPI_Cartdim_get(MPI_Comm comm, int *ndims);
static inline int MPI_Cartdim_get(MPI_Comm comm, int *ndims) {
  return multimpi_MPI_Cartdim_get(comm, ndims);
}

int multimpi_MPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result);
static inline int MPI_Group_compare(MPI_Group group1, MPI_Group group2,
                                    int *result) {
  return multimpi_MPI_Group_compare(group1, group2, result);
}

int multimpi_MPI_T_pvar_readreset(MPI_T_pvar_session session,
                                  MPI_T_pvar_handle handle, void *buf);
static inline int MPI_T_pvar_readreset(MPI_T_pvar_session session,
                                       MPI_T_pvar_handle handle, void *buf) {
  return multimpi_MPI_T_pvar_readreset(session, handle, buf);
}

int multimpi_MPI_Close_port(const char *port_name);
static inline int MPI_Close_port(const char *port_name) {
  return multimpi_MPI_Close_port(port_name);
}

int multimpi_MPI_Group_difference(MPI_Group group1, MPI_Group group2,
                                  MPI_Group *newgroup);
static inline int MPI_Group_difference(MPI_Group group1, MPI_Group group2,
                                       MPI_Group *newgroup) {
  return multimpi_MPI_Group_difference(group1, group2, newgroup);
}

int multimpi_MPI_T_pvar_reset(MPI_T_pvar_session session,
                              MPI_T_pvar_handle handle);
static inline int MPI_T_pvar_reset(MPI_T_pvar_session session,
                                   MPI_T_pvar_handle handle) {
  return multimpi_MPI_T_pvar_reset(session, handle);
}

int multimpi_MPI_Comm_accept(const char *port_name, MPI_Info info, int root,
                             MPI_Comm comm, MPI_Comm *newcomm);
static inline int MPI_Comm_accept(const char *port_name, MPI_Info info,
                                  int root, MPI_Comm comm, MPI_Comm *newcomm) {
  return multimpi_MPI_Comm_accept(port_name, info, root, comm, newcomm);
}

int multimpi_MPI_Group_excl(MPI_Group group, int n, const int ranks[],
                            MPI_Group *newgroup);
static inline int MPI_Group_excl(MPI_Group group, int n, const int ranks[],
                                 MPI_Group *newgroup) {
  return multimpi_MPI_Group_excl(group, n, ranks, newgroup);
}

int multimpi_MPI_T_pvar_session_create(MPI_T_pvar_session *session);
static inline int MPI_T_pvar_session_create(MPI_T_pvar_session *session) {
  return multimpi_MPI_T_pvar_session_create(session);
}

int multimpi_MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode);
static inline int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode) {
  return multimpi_MPI_Comm_call_errhandler(comm, errorcode);
}

int multimpi_MPI_Group_free(MPI_Group *group);
static inline int MPI_Group_free(MPI_Group *group) {
  return multimpi_MPI_Group_free(group);
}

int multimpi_MPI_T_pvar_session_free(MPI_T_pvar_session *session);
static inline int MPI_T_pvar_session_free(MPI_T_pvar_session *session) {
  return multimpi_MPI_T_pvar_session_free(session);
}

int multimpi_MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result);
static inline int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2,
                                   int *result) {
  return multimpi_MPI_Comm_compare(comm1, comm2, result);
}

int multimpi_MPI_Group_incl(MPI_Group group, int n, const int ranks[],
                            MPI_Group *newgroup);
static inline int MPI_Group_incl(MPI_Group group, int n, const int ranks[],
                                 MPI_Group *newgroup) {
  return multimpi_MPI_Group_incl(group, n, ranks, newgroup);
}

int multimpi_MPI_T_pvar_start(MPI_T_pvar_session session,
                              MPI_T_pvar_handle handle);
static inline int MPI_T_pvar_start(MPI_T_pvar_session session,
                                   MPI_T_pvar_handle handle) {
  return multimpi_MPI_T_pvar_start(session, handle);
}

int multimpi_MPI_Comm_connect(const char *port_name, MPI_Info info, int root,
                              MPI_Comm comm, MPI_Comm *newcomm);
static inline int MPI_Comm_connect(const char *port_name, MPI_Info info,
                                   int root, MPI_Comm comm, MPI_Comm *newcomm) {
  return multimpi_MPI_Comm_connect(port_name, info, root, comm, newcomm);
}

int multimpi_MPI_Group_intersection(MPI_Group group1, MPI_Group group2,
                                    MPI_Group *newgroup);
static inline int MPI_Group_intersection(MPI_Group group1, MPI_Group group2,
                                         MPI_Group *newgroup) {
  return multimpi_MPI_Group_intersection(group1, group2, newgroup);
}

int multimpi_MPI_T_pvar_stop(MPI_T_pvar_session session,
                             MPI_T_pvar_handle handle);
static inline int MPI_T_pvar_stop(MPI_T_pvar_session session,
                                  MPI_T_pvar_handle handle) {
  return multimpi_MPI_T_pvar_stop(session, handle);
}

int multimpi_MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm);
static inline int MPI_Comm_create(MPI_Comm comm, MPI_Group group,
                                  MPI_Comm *newcomm) {
  return multimpi_MPI_Comm_create(comm, group, newcomm);
}

int multimpi_MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
                                  MPI_Group *newgroup);
static inline int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
                                       MPI_Group *newgroup) {
  return multimpi_MPI_Group_range_excl(group, n, ranges, newgroup);
}

int multimpi_MPI_T_pvar_write(MPI_T_pvar_session session,
                              MPI_T_pvar_handle handle, void *buf);
static inline int MPI_T_pvar_write(MPI_T_pvar_session session,
                                   MPI_T_pvar_handle handle, void *buf) {
  return multimpi_MPI_T_pvar_write(session, handle, buf);
}

int multimpi_MPI_Comm_create_errhandler(
    MPI_Comm_errhandler_function *comm_errhandler_fn,
    MPI_Errhandler *errhandler);
static inline int
MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn,
                           MPI_Errhandler *errhandler) {
  return multimpi_MPI_Comm_create_errhandler(comm_errhandler_fn, errhandler);
}

int multimpi_MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3],
                                  MPI_Group *newgroup);
static inline int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3],
                                       MPI_Group *newgroup) {
  return multimpi_MPI_Group_range_incl(group, n, ranges, newgroup);
}

int multimpi_MPI_Test(MPI_Request *request, int *flag, MPI_Status *status);
static inline int MPI_Test(MPI_Request *request, int *flag,
                           MPI_Status *status) {
  return multimpi_MPI_Test(request, flag, status);
}

int multimpi_MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag,
                                   MPI_Comm *newcomm);
static inline int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag,
                                        MPI_Comm *newcomm) {
  return multimpi_MPI_Comm_create_group(comm, group, tag, newcomm);
}

int multimpi_MPI_Group_rank(MPI_Group group, int *rank);
static inline int MPI_Group_rank(MPI_Group group, int *rank) {
  return multimpi_MPI_Group_rank(group, rank);
}

int multimpi_MPI_Test_cancelled(const MPI_Status *status, int *flag);
static inline int MPI_Test_cancelled(const MPI_Status *status, int *flag) {
  return multimpi_MPI_Test_cancelled(status, flag);
}

int multimpi_MPI_Comm_create_keyval(
    MPI_Comm_copy_attr_function *comm_copy_attr_fn,
    MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
    void *extra_state);
static inline int
MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                       MPI_Comm_delete_attr_function *comm_delete_attr_fn,
                       int *comm_keyval, void *extra_state) {
  return multimpi_MPI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn,
                                         comm_keyval, extra_state);
}

int multimpi_MPI_Group_size(MPI_Group group, int *size);
static inline int MPI_Group_size(MPI_Group group, int *size) {
  return multimpi_MPI_Group_size(group, size);
}

int multimpi_MPI_Testall(int count, MPI_Request array_of_requests[], int *flag,
                         MPI_Status array_of_statuses[]);
static inline int MPI_Testall(int count, MPI_Request array_of_requests[],
                              int *flag, MPI_Status array_of_statuses[]) {
  return multimpi_MPI_Testall(count, array_of_requests, flag,
                              array_of_statuses);
}

int multimpi_MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval);
static inline int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval) {
  return multimpi_MPI_Comm_delete_attr(comm, comm_keyval);
}

int multimpi_MPI_Group_translate_ranks(MPI_Group group1, int n,
                                       const int ranks1[], MPI_Group group2,
                                       int ranks2[]);
static inline int MPI_Group_translate_ranks(MPI_Group group1, int n,
                                            const int ranks1[],
                                            MPI_Group group2, int ranks2[]) {
  return multimpi_MPI_Group_translate_ranks(group1, n, ranks1, group2, ranks2);
}

int multimpi_MPI_Testany(int count, MPI_Request array_of_requests[], int *indx,
                         int *flag, MPI_Status *status);
static inline int MPI_Testany(int count, MPI_Request array_of_requests[],
                              int *indx, int *flag, MPI_Status *status) {
  return multimpi_MPI_Testany(count, array_of_requests, indx, flag, status);
}

int multimpi_MPI_Comm_disconnect(MPI_Comm *comm);
static inline int MPI_Comm_disconnect(MPI_Comm *comm) {
  return multimpi_MPI_Comm_disconnect(comm);
}

int multimpi_MPI_Group_union(MPI_Group group1, MPI_Group group2,
                             MPI_Group *newgroup);
static inline int MPI_Group_union(MPI_Group group1, MPI_Group group2,
                                  MPI_Group *newgroup) {
  return multimpi_MPI_Group_union(group1, group2, newgroup);
}

int multimpi_MPI_Testsome(int incount, MPI_Request array_of_requests[],
                          int *outcount, int array_of_indices[],
                          MPI_Status array_of_statuses[]);
static inline int MPI_Testsome(int incount, MPI_Request array_of_requests[],
                               int *outcount, int array_of_indices[],
                               MPI_Status array_of_statuses[]) {
  return multimpi_MPI_Testsome(incount, array_of_requests, outcount,
                               array_of_indices, array_of_statuses);
}

int multimpi_MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);
static inline int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) {
  return multimpi_MPI_Comm_dup(comm, newcomm);
}

int multimpi_MPI_Iallgather(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf, int recvcount,
                            MPI_Datatype recvtype, MPI_Comm comm,
                            MPI_Request *request);
static inline int MPI_Iallgather(const void *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 int recvcount, MPI_Datatype recvtype,
                                 MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Iallgather(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcount, recvtype, comm, request);
}

int multimpi_MPI_Topo_test(MPI_Comm comm, int *status);
static inline int MPI_Topo_test(MPI_Comm comm, int *status) {
  return multimpi_MPI_Topo_test(comm, status);
}

int multimpi_MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info,
                                    MPI_Comm *newcomm);
static inline int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info,
                                         MPI_Comm *newcomm) {
  return multimpi_MPI_Comm_dup_with_info(comm, info, newcomm);
}

int multimpi_MPI_Iallgatherv(const void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             const int recvcounts[], const int displs[],
                             MPI_Datatype recvtype, MPI_Comm comm,
                             MPI_Request *request);
static inline int MPI_Iallgatherv(const void *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  const int recvcounts[], const int displs[],
                                  MPI_Datatype recvtype, MPI_Comm comm,
                                  MPI_Request *request) {
  return multimpi_MPI_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf,
                                  recvcounts, displs, recvtype, comm, request);
}

int multimpi_MPI_Type_commit(MPI_Datatype *datatype);
static inline int MPI_Type_commit(MPI_Datatype *datatype) {
  return multimpi_MPI_Type_commit(datatype);
}

int multimpi_MPI_Comm_free(MPI_Comm *comm);
static inline int MPI_Comm_free(MPI_Comm *comm) {
  return multimpi_MPI_Comm_free(comm);
}

int multimpi_MPI_Iallreduce(const void *sendbuf, void *recvbuf, int count,
                            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                            MPI_Request *request);
static inline int MPI_Iallreduce(const void *sendbuf, void *recvbuf, int count,
                                 MPI_Datatype datatype, MPI_Op op,
                                 MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Iallreduce(sendbuf, recvbuf, count, datatype, op, comm,
                                 request);
}

int multimpi_MPI_Type_contiguous(int count, MPI_Datatype oldtype,
                                 MPI_Datatype *newtype);
static inline int MPI_Type_contiguous(int count, MPI_Datatype oldtype,
                                      MPI_Datatype *newtype) {
  return multimpi_MPI_Type_contiguous(count, oldtype, newtype);
}

int multimpi_MPI_Comm_free_keyval(int *comm_keyval);
static inline int MPI_Comm_free_keyval(int *comm_keyval) {
  return multimpi_MPI_Comm_free_keyval(comm_keyval);
}

int multimpi_MPI_Ialltoall(const void *sendbuf, int sendcount,
                           MPI_Datatype sendtype, void *recvbuf, int recvcount,
                           MPI_Datatype recvtype, MPI_Comm comm,
                           MPI_Request *request);
static inline int MPI_Ialltoall(const void *sendbuf, int sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                int recvcount, MPI_Datatype recvtype,
                                MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm, request);
}

int multimpi_MPI_Type_create_darray(int size, int rank, int ndims,
                                    const int array_of_gsizes[],
                                    const int array_of_distribs[],
                                    const int array_of_dargs[],
                                    const int array_of_psizes[], int order,
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype);
static inline int MPI_Type_create_darray(int size, int rank, int ndims,
                                         const int array_of_gsizes[],
                                         const int array_of_distribs[],
                                         const int array_of_dargs[],
                                         const int array_of_psizes[], int order,
                                         MPI_Datatype oldtype,
                                         MPI_Datatype *newtype) {
  return multimpi_MPI_Type_create_darray(
      size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs,
      array_of_psizes, order, oldtype, newtype);
}

int multimpi_MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval,
                               void *attribute_val, int *flag);
static inline int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval,
                                    void *attribute_val, int *flag) {
  return multimpi_MPI_Comm_get_attr(comm, comm_keyval, attribute_val, flag);
}

int multimpi_MPI_Ialltoallv(const void *sendbuf, const int sendcounts[],
                            const int sdispls[], MPI_Datatype sendtype,
                            void *recvbuf, const int recvcounts[],
                            const int rdispls[], MPI_Datatype recvtype,
                            MPI_Comm comm, MPI_Request *request);
static inline int MPI_Ialltoallv(const void *sendbuf, const int sendcounts[],
                                 const int sdispls[], MPI_Datatype sendtype,
                                 void *recvbuf, const int recvcounts[],
                                 const int rdispls[], MPI_Datatype recvtype,
                                 MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype,
                                 recvbuf, recvcounts, rdispls, recvtype, comm,
                                 request);
}

int multimpi_MPI_Type_create_f90_complex(int precision, int range,
                                         MPI_Datatype *newtype);
static inline int MPI_Type_create_f90_complex(int precision, int range,
                                              MPI_Datatype *newtype) {
  return multimpi_MPI_Type_create_f90_complex(precision, range, newtype);
}

int multimpi_MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler);
static inline int MPI_Comm_get_errhandler(MPI_Comm comm,
                                          MPI_Errhandler *errhandler) {
  return multimpi_MPI_Comm_get_errhandler(comm, errhandler);
}

int multimpi_MPI_Ialltoallw(const void *sendbuf, const int sendcounts[],
                            const int sdispls[], const MPI_Datatype sendtypes[],
                            void *recvbuf, const int recvcounts[],
                            const int rdispls[], const MPI_Datatype recvtypes[],
                            MPI_Comm comm, MPI_Request *request);
static inline int MPI_Ialltoallw(const void *sendbuf, const int sendcounts[],
                                 const int sdispls[],
                                 const MPI_Datatype sendtypes[], void *recvbuf,
                                 const int recvcounts[], const int rdispls[],
                                 const MPI_Datatype recvtypes[], MPI_Comm comm,
                                 MPI_Request *request) {
  return multimpi_MPI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes,
                                 recvbuf, recvcounts, rdispls, recvtypes, comm,
                                 request);
}

int multimpi_MPI_Type_create_f90_integer(int range, MPI_Datatype *newtype);
static inline int MPI_Type_create_f90_integer(int range,
                                              MPI_Datatype *newtype) {
  return multimpi_MPI_Type_create_f90_integer(range, newtype);
}

int multimpi_MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used);
static inline int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used) {
  return multimpi_MPI_Comm_get_info(comm, info_used);
}

int multimpi_MPI_Ibarrier(MPI_Comm comm, MPI_Request *request);
static inline int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Ibarrier(comm, request);
}

int multimpi_MPI_Type_create_f90_real(int precision, int range,
                                      MPI_Datatype *newtype);
static inline int MPI_Type_create_f90_real(int precision, int range,
                                           MPI_Datatype *newtype) {
  return multimpi_MPI_Type_create_f90_real(precision, range, newtype);
}

int multimpi_MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen);
static inline int MPI_Comm_get_name(MPI_Comm comm, char *comm_name,
                                    int *resultlen) {
  return multimpi_MPI_Comm_get_name(comm, comm_name, resultlen);
}

int multimpi_MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype,
                        int root, MPI_Comm comm, MPI_Request *request);
static inline int MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype,
                             int root, MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Ibcast(buffer, count, datatype, root, comm, request);
}

int multimpi_MPI_Type_create_hindexed(int count,
                                      const int array_of_blocklengths[],
                                      const MPI_Aint array_of_displacements[],
                                      MPI_Datatype oldtype,
                                      MPI_Datatype *newtype);
static inline int
MPI_Type_create_hindexed(int count, const int array_of_blocklengths[],
                         const MPI_Aint array_of_displacements[],
                         MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return multimpi_MPI_Type_create_hindexed(
      count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
}

int multimpi_MPI_Comm_get_parent(MPI_Comm *parent);
static inline int MPI_Comm_get_parent(MPI_Comm *parent) {
  return multimpi_MPI_Comm_get_parent(parent);
}

int multimpi_MPI_Ibsend(const void *buf, int count, MPI_Datatype datatype,
                        int dest, int tag, MPI_Comm comm, MPI_Request *request);
static inline int MPI_Ibsend(const void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm,
                             MPI_Request *request) {
  return multimpi_MPI_Ibsend(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Type_create_hindexed_block(
    int count, int blocklength, const MPI_Aint array_of_displacements[],
    MPI_Datatype oldtype, MPI_Datatype *newtype);
static inline int
MPI_Type_create_hindexed_block(int count, int blocklength,
                               const MPI_Aint array_of_displacements[],
                               MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return multimpi_MPI_Type_create_hindexed_block(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

int multimpi_MPI_Comm_group(MPI_Comm comm, MPI_Group *group);
static inline int MPI_Comm_group(MPI_Comm comm, MPI_Group *group) {
  return multimpi_MPI_Comm_group(comm, group);
}

int multimpi_MPI_Iexscan(const void *sendbuf, void *recvbuf, int count,
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                         MPI_Request *request);
static inline int MPI_Iexscan(const void *sendbuf, void *recvbuf, int count,
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                              MPI_Request *request) {
  return multimpi_MPI_Iexscan(sendbuf, recvbuf, count, datatype, op, comm,
                              request);
}

int multimpi_MPI_Type_create_hvector(int count, int blocklength,
                                     MPI_Aint stride, MPI_Datatype oldtype,
                                     MPI_Datatype *newtype);
static inline int MPI_Type_create_hvector(int count, int blocklength,
                                          MPI_Aint stride, MPI_Datatype oldtype,
                                          MPI_Datatype *newtype) {
  return multimpi_MPI_Type_create_hvector(count, blocklength, stride, oldtype,
                                          newtype);
}

int multimpi_MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm,
                           MPI_Request *request);
static inline int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm,
                                MPI_Request *request) {
  return multimpi_MPI_Comm_idup(comm, newcomm, request);
}

int multimpi_MPI_Igather(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, void *recvbuf, int recvcount,
                         MPI_Datatype recvtype, int root, MPI_Comm comm,
                         MPI_Request *request);
static inline int MPI_Igather(const void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              int recvcount, MPI_Datatype recvtype, int root,
                              MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Igather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                              recvtype, root, comm, request);
}

int multimpi_MPI_Type_create_indexed_block(int count, int blocklength,
                                           const int array_of_displacements[],
                                           MPI_Datatype oldtype,
                                           MPI_Datatype *newtype);
static inline int
MPI_Type_create_indexed_block(int count, int blocklength,
                              const int array_of_displacements[],
                              MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return multimpi_MPI_Type_create_indexed_block(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

int multimpi_MPI_Comm_join(int fd, MPI_Comm *intercomm);
static inline int MPI_Comm_join(int fd, MPI_Comm *intercomm) {
  return multimpi_MPI_Comm_join(fd, intercomm);
}

int multimpi_MPI_Igatherv(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          const int recvcounts[], const int displs[],
                          MPI_Datatype recvtype, int root, MPI_Comm comm,
                          MPI_Request *request);
static inline int MPI_Igatherv(const void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               const int recvcounts[], const int displs[],
                               MPI_Datatype recvtype, int root, MPI_Comm comm,
                               MPI_Request *request) {
  return multimpi_MPI_Igatherv(sendbuf, sendcount, sendtype, recvbuf,
                               recvcounts, displs, recvtype, root, comm,
                               request);
}

int multimpi_MPI_Type_create_keyval(
    MPI_Type_copy_attr_function *type_copy_attr_fn,
    MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval,
    void *extra_state);
static inline int
MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn,
                       MPI_Type_delete_attr_function *type_delete_attr_fn,
                       int *type_keyval, void *extra_state) {
  return multimpi_MPI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn,
                                         type_keyval, extra_state);
}

int multimpi_MPI_Comm_rank(MPI_Comm comm, int *rank);
static inline int MPI_Comm_rank(MPI_Comm comm, int *rank) {
  return multimpi_MPI_Comm_rank(comm, rank);
}

int multimpi_MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag,
                         MPI_Message *message, MPI_Status *status);
static inline int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag,
                              MPI_Message *message, MPI_Status *status) {
  return multimpi_MPI_Improbe(source, tag, comm, flag, message, status);
}

int multimpi_MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb,
                                     MPI_Aint extent, MPI_Datatype *newtype);
static inline int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb,
                                          MPI_Aint extent,
                                          MPI_Datatype *newtype) {
  return multimpi_MPI_Type_create_resized(oldtype, lb, extent, newtype);
}

int multimpi_MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group);
static inline int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group) {
  return multimpi_MPI_Comm_remote_group(comm, group);
}

int multimpi_MPI_Imrecv(void *buf, int count, MPI_Datatype datatype,
                        MPI_Message *message, MPI_Request *request);
static inline int MPI_Imrecv(void *buf, int count, MPI_Datatype datatype,
                             MPI_Message *message, MPI_Request *request) {
  return multimpi_MPI_Imrecv(buf, count, datatype, message, request);
}

int multimpi_MPI_Type_create_struct(int count,
                                    const int array_of_blocklengths[],
                                    const MPI_Aint array_of_displacements[],
                                    const MPI_Datatype array_of_types[],
                                    MPI_Datatype *newtype);
static inline int
MPI_Type_create_struct(int count, const int array_of_blocklengths[],
                       const MPI_Aint array_of_displacements[],
                       const MPI_Datatype array_of_types[],
                       MPI_Datatype *newtype) {
  return multimpi_MPI_Type_create_struct(count, array_of_blocklengths,
                                         array_of_displacements, array_of_types,
                                         newtype);
}

int multimpi_MPI_Comm_remote_size(MPI_Comm comm, int *size);
static inline int MPI_Comm_remote_size(MPI_Comm comm, int *size) {
  return multimpi_MPI_Comm_remote_size(comm, size);
}

int multimpi_MPI_Ineighbor_allgather(const void *sendbuf, int sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     int recvcount, MPI_Datatype recvtype,
                                     MPI_Comm comm, MPI_Request *request);
static inline int MPI_Ineighbor_allgather(const void *sendbuf, int sendcount,
                                          MPI_Datatype sendtype, void *recvbuf,
                                          int recvcount, MPI_Datatype recvtype,
                                          MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf,
                                          recvcount, recvtype, comm, request);
}

int multimpi_MPI_Type_create_subarray(int ndims, const int array_of_sizes[],
                                      const int array_of_subsizes[],
                                      const int array_of_starts[], int order,
                                      MPI_Datatype oldtype,
                                      MPI_Datatype *newtype);
static inline int MPI_Type_create_subarray(int ndims,
                                           const int array_of_sizes[],
                                           const int array_of_subsizes[],
                                           const int array_of_starts[],
                                           int order, MPI_Datatype oldtype,
                                           MPI_Datatype *newtype) {
  return multimpi_MPI_Type_create_subarray(ndims, array_of_sizes,
                                           array_of_subsizes, array_of_starts,
                                           order, oldtype, newtype);
}

int multimpi_MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval,
                               void *attribute_val);
static inline int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval,
                                    void *attribute_val) {
  return multimpi_MPI_Comm_set_attr(comm, comm_keyval, attribute_val);
}

int multimpi_MPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      const int recvcounts[],
                                      const int displs[], MPI_Datatype recvtype,
                                      MPI_Comm comm, MPI_Request *request);
static inline int MPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount,
                                           MPI_Datatype sendtype, void *recvbuf,
                                           const int recvcounts[],
                                           const int displs[],
                                           MPI_Datatype recvtype, MPI_Comm comm,
                                           MPI_Request *request) {
  return multimpi_MPI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype,
                                           recvbuf, recvcounts, displs,
                                           recvtype, comm, request);
}

int multimpi_MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval);
static inline int MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval) {
  return multimpi_MPI_Type_delete_attr(datatype, type_keyval);
}

int multimpi_MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler);
static inline int MPI_Comm_set_errhandler(MPI_Comm comm,
                                          MPI_Errhandler errhandler) {
  return multimpi_MPI_Comm_set_errhandler(comm, errhandler);
}

int multimpi_MPI_Ineighbor_alltoall(const void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    int recvcount, MPI_Datatype recvtype,
                                    MPI_Comm comm, MPI_Request *request);
static inline int MPI_Ineighbor_alltoall(const void *sendbuf, int sendcount,
                                         MPI_Datatype sendtype, void *recvbuf,
                                         int recvcount, MPI_Datatype recvtype,
                                         MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf,
                                         recvcount, recvtype, comm, request);
}

int multimpi_MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype);
static inline int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return multimpi_MPI_Type_dup(oldtype, newtype);
}

int multimpi_MPI_Comm_set_info(MPI_Comm comm, MPI_Info info);
static inline int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info) {
  return multimpi_MPI_Comm_set_info(comm, info);
}

int multimpi_MPI_Ineighbor_alltoallv(const void *sendbuf,
                                     const int sendcounts[],
                                     const int sdispls[], MPI_Datatype sendtype,
                                     void *recvbuf, const int recvcounts[],
                                     const int rdispls[], MPI_Datatype recvtype,
                                     MPI_Comm comm, MPI_Request *request);
static inline int
MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                        const int sdispls[], MPI_Datatype sendtype,
                        void *recvbuf, const int recvcounts[],
                        const int rdispls[], MPI_Datatype recvtype,
                        MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls,
                                          sendtype, recvbuf, recvcounts,
                                          rdispls, recvtype, comm, request);
}

int multimpi_MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent);
static inline int MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent) {
  return multimpi_MPI_Type_extent(datatype, extent);
}

int multimpi_MPI_Comm_set_name(MPI_Comm comm, const char *comm_name);
static inline int MPI_Comm_set_name(MPI_Comm comm, const char *comm_name) {
  return multimpi_MPI_Comm_set_name(comm, comm_name);
}

int multimpi_MPI_Ineighbor_alltoallw(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Request *request);
static inline int MPI_Ineighbor_alltoallw(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Request *request) {
  return multimpi_MPI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls,
                                          sendtypes, recvbuf, recvcounts,
                                          rdispls, recvtypes, comm, request);
}

int multimpi_MPI_Type_free(MPI_Datatype *datatype);
static inline int MPI_Type_free(MPI_Datatype *datatype) {
  return multimpi_MPI_Type_free(datatype);
}

int multimpi_MPI_Comm_size(MPI_Comm comm, int *size);
static inline int MPI_Comm_size(MPI_Comm comm, int *size) {
  return multimpi_MPI_Comm_size(comm, size);
}

int multimpi_MPI_Info_create(MPI_Info *info);
static inline int MPI_Info_create(MPI_Info *info) {
  return multimpi_MPI_Info_create(info);
}

int multimpi_MPI_Type_free_keyval(int *type_keyval);
static inline int MPI_Type_free_keyval(int *type_keyval) {
  return multimpi_MPI_Type_free_keyval(type_keyval);
}

int multimpi_MPI_Comm_spawn(const char *command, char *argv[], int maxprocs,
                            MPI_Info info, int root, MPI_Comm comm,
                            MPI_Comm *intercomm, int array_of_errcodes[]);
static inline int MPI_Comm_spawn(const char *command, char *argv[],
                                 int maxprocs, MPI_Info info, int root,
                                 MPI_Comm comm, MPI_Comm *intercomm,
                                 int array_of_errcodes[]) {
  return multimpi_MPI_Comm_spawn(command, argv, maxprocs, info, root, comm,
                                 intercomm, array_of_errcodes);
}

int multimpi_MPI_Info_delete(MPI_Info info, const char *key);
static inline int MPI_Info_delete(MPI_Info info, const char *key) {
  return multimpi_MPI_Info_delete(info, key);
}

int multimpi_MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval,
                               void *attribute_val, int *flag);
static inline int MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval,
                                    void *attribute_val, int *flag) {
  return multimpi_MPI_Type_get_attr(datatype, type_keyval, attribute_val, flag);
}

int multimpi_MPI_Comm_spawn_multiple(int count, char *array_of_commands[],
                                     char **array_of_argv[],
                                     const int array_of_maxprocs[],
                                     const MPI_Info array_of_info[], int root,
                                     MPI_Comm comm, MPI_Comm *intercomm,
                                     int array_of_errcodes[]);
static inline int
MPI_Comm_spawn_multiple(int count, char *array_of_commands[],
                        char **array_of_argv[], const int array_of_maxprocs[],
                        const MPI_Info array_of_info[], int root, MPI_Comm comm,
                        MPI_Comm *intercomm, int array_of_errcodes[]) {
  return multimpi_MPI_Comm_spawn_multiple(
      count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info,
      root, comm, intercomm, array_of_errcodes);
}

int multimpi_MPI_Info_dup(MPI_Info info, MPI_Info *newinfo);
static inline int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo) {
  return multimpi_MPI_Info_dup(info, newinfo);
}

int multimpi_MPI_Type_get_contents(MPI_Datatype datatype, int max_integers,
                                   int max_addresses, int max_datatypes,
                                   int array_of_integers[],
                                   MPI_Aint array_of_addresses[],
                                   MPI_Datatype array_of_datatypes[]);
static inline int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers,
                                        int max_addresses, int max_datatypes,
                                        int array_of_integers[],
                                        MPI_Aint array_of_addresses[],
                                        MPI_Datatype array_of_datatypes[]) {
  return multimpi_MPI_Type_get_contents(datatype, max_integers, max_addresses,
                                        max_datatypes, array_of_integers,
                                        array_of_addresses, array_of_datatypes);
}

int multimpi_MPI_Comm_split(MPI_Comm comm, int color, int key,
                            MPI_Comm *newcomm);
static inline int MPI_Comm_split(MPI_Comm comm, int color, int key,
                                 MPI_Comm *newcomm) {
  return multimpi_MPI_Comm_split(comm, color, key, newcomm);
}

int multimpi_MPI_Info_free(MPI_Info *info);
static inline int MPI_Info_free(MPI_Info *info) {
  return multimpi_MPI_Info_free(info);
}

int multimpi_MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers,
                                   int *num_addresses, int *num_datatypes,
                                   int *combiner);
static inline int MPI_Type_get_envelope(MPI_Datatype datatype,
                                        int *num_integers, int *num_addresses,
                                        int *num_datatypes, int *combiner) {
  return multimpi_MPI_Type_get_envelope(datatype, num_integers, num_addresses,
                                        num_datatypes, combiner);
}

int multimpi_MPI_Comm_split_type(MPI_Comm comm, int split_type, int key,
                                 MPI_Info info, MPI_Comm *newcomm);
static inline int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key,
                                      MPI_Info info, MPI_Comm *newcomm) {
  return multimpi_MPI_Comm_split_type(comm, split_type, key, info, newcomm);
}

int multimpi_MPI_Info_get(MPI_Info info, const char *key, int valuelen,
                          char *value, int *flag);
static inline int MPI_Info_get(MPI_Info info, const char *key, int valuelen,
                               char *value, int *flag) {
  return multimpi_MPI_Info_get(info, key, valuelen, value, flag);
}

int multimpi_MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb,
                                 MPI_Aint *extent);
static inline int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb,
                                      MPI_Aint *extent) {
  return multimpi_MPI_Type_get_extent(datatype, lb, extent);
}

int multimpi_MPI_Comm_test_inter(MPI_Comm comm, int *flag);
static inline int MPI_Comm_test_inter(MPI_Comm comm, int *flag) {
  return multimpi_MPI_Comm_test_inter(comm, flag);
}

int multimpi_MPI_Info_get_nkeys(MPI_Info info, int *nkeys);
static inline int MPI_Info_get_nkeys(MPI_Info info, int *nkeys) {
  return multimpi_MPI_Info_get_nkeys(info, nkeys);
}

int multimpi_MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                                   MPI_Count *extent);
static inline int MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                                        MPI_Count *extent) {
  return multimpi_MPI_Type_get_extent_x(datatype, lb, extent);
}

int multimpi_MPI_Compare_and_swap(const void *origin_addr,
                                  const void *compare_addr, void *result_addr,
                                  MPI_Datatype datatype, int target_rank,
                                  MPI_Aint target_disp, MPI_Win win);
static inline int MPI_Compare_and_swap(const void *origin_addr,
                                       const void *compare_addr,
                                       void *result_addr, MPI_Datatype datatype,
                                       int target_rank, MPI_Aint target_disp,
                                       MPI_Win win) {
  return multimpi_MPI_Compare_and_swap(origin_addr, compare_addr, result_addr,
                                       datatype, target_rank, target_disp, win);
}

int multimpi_MPI_Info_get_nthkey(MPI_Info info, int n, char *key);
static inline int MPI_Info_get_nthkey(MPI_Info info, int n, char *key) {
  return multimpi_MPI_Info_get_nthkey(info, n, key);
}

int multimpi_MPI_Type_get_name(MPI_Datatype datatype, char *type_name,
                               int *resultlen);
static inline int MPI_Type_get_name(MPI_Datatype datatype, char *type_name,
                                    int *resultlen) {
  return multimpi_MPI_Type_get_name(datatype, type_name, resultlen);
}

int multimpi_MPI_Dims_create(int nnodes, int ndims, int dims[]);
static inline int MPI_Dims_create(int nnodes, int ndims, int dims[]) {
  return multimpi_MPI_Dims_create(nnodes, ndims, dims);
}

int multimpi_MPI_Info_get_valuelen(MPI_Info info, const char *key,
                                   int *valuelen, int *flag);
static inline int MPI_Info_get_valuelen(MPI_Info info, const char *key,
                                        int *valuelen, int *flag) {
  return multimpi_MPI_Info_get_valuelen(info, key, valuelen, flag);
}

int multimpi_MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb,
                                      MPI_Aint *true_extent);
static inline int MPI_Type_get_true_extent(MPI_Datatype datatype,
                                           MPI_Aint *true_lb,
                                           MPI_Aint *true_extent) {
  return multimpi_MPI_Type_get_true_extent(datatype, true_lb, true_extent);
}

int multimpi_MPI_Dist_graph_create(MPI_Comm comm_old, int n,
                                   const int sources[], const int degrees[],
                                   const int destinations[],
                                   const int weights[], MPI_Info info,
                                   int reorder, MPI_Comm *comm_dist_graph);
static inline int
MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[],
                      const int degrees[], const int destinations[],
                      const int weights[], MPI_Info info, int reorder,
                      MPI_Comm *comm_dist_graph) {
  return multimpi_MPI_Dist_graph_create(comm_old, n, sources, degrees,
                                        destinations, weights, info, reorder,
                                        comm_dist_graph);
}

int multimpi_MPI_Info_set(MPI_Info info, const char *key, const char *value);
static inline int MPI_Info_set(MPI_Info info, const char *key,
                               const char *value) {
  return multimpi_MPI_Info_set(info, key, value);
}

int multimpi_MPI_Type_get_true_extent_x(MPI_Datatype datatype,
                                        MPI_Count *true_lb,
                                        MPI_Count *true_extent);
static inline int MPI_Type_get_true_extent_x(MPI_Datatype datatype,
                                             MPI_Count *true_lb,
                                             MPI_Count *true_extent) {
  return multimpi_MPI_Type_get_true_extent_x(datatype, true_lb, true_extent);
}

int multimpi_MPI_Dist_graph_create_adjacent(
    MPI_Comm comm_old, int indegree, const int sources[],
    const int sourceweights[], int outdegree, const int destinations[],
    const int destweights[], MPI_Info info, int reorder,
    MPI_Comm *comm_dist_graph);
static inline int
MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree,
                               const int sources[], const int sourceweights[],
                               int outdegree, const int destinations[],
                               const int destweights[], MPI_Info info,
                               int reorder, MPI_Comm *comm_dist_graph) {
  return multimpi_MPI_Dist_graph_create_adjacent(
      comm_old, indegree, sources, sourceweights, outdegree, destinations,
      destweights, info, reorder, comm_dist_graph);
}

int multimpi_MPI_Init(int *argc, char ***argv);
static inline int MPI_Init(int *argc, char ***argv) {
  return multimpi_MPI_Init(argc, argv);
}

int multimpi_MPI_Type_hindexed(int count, const int *array_of_blocklengths,
                               const MPI_Aint *array_of_displacements,
                               MPI_Datatype oldtype, MPI_Datatype *newtype);
static inline int MPI_Type_hindexed(int count, const int *array_of_blocklengths,
                                    const MPI_Aint *array_of_displacements,
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype) {
  return multimpi_MPI_Type_hindexed(count, array_of_blocklengths,
                                    array_of_displacements, oldtype, newtype);
}

int multimpi_MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree,
                                      int sources[], int sourceweights[],
                                      int maxoutdegree, int destinations[],
                                      int destweights[]);
static inline int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree,
                                           int sources[], int sourceweights[],
                                           int maxoutdegree, int destinations[],
                                           int destweights[]) {
  return multimpi_MPI_Dist_graph_neighbors(comm, maxindegree, sources,
                                           sourceweights, maxoutdegree,
                                           destinations, destweights);
}

int multimpi_MPI_Init_thread(int *argc, char ***argv, int required,
                             int *provided);
static inline int MPI_Init_thread(int *argc, char ***argv, int required,
                                  int *provided) {
  return multimpi_MPI_Init_thread(argc, argv, required, provided);
}

int multimpi_MPI_Type_hvector(int count, int blocklength, MPI_Aint stride,
                              MPI_Datatype oldtype, MPI_Datatype *newtype);
static inline int MPI_Type_hvector(int count, int blocklength, MPI_Aint stride,
                                   MPI_Datatype oldtype,
                                   MPI_Datatype *newtype) {
  return multimpi_MPI_Type_hvector(count, blocklength, stride, oldtype,
                                   newtype);
}

int multimpi_MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree,
                                            int *outdegree, int *weighted);
static inline int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree,
                                                 int *outdegree,
                                                 int *weighted) {
  return multimpi_MPI_Dist_graph_neighbors_count(comm, indegree, outdegree,
                                                 weighted);
}

int multimpi_MPI_Initialized(int *flag);
static inline int MPI_Initialized(int *flag) {
  return multimpi_MPI_Initialized(flag);
}

int multimpi_MPI_Type_indexed(int count, const int *array_of_blocklengths,
                              const int *array_of_displacements,
                              MPI_Datatype oldtype, MPI_Datatype *newtype);
static inline int MPI_Type_indexed(int count, const int *array_of_blocklengths,
                                   const int *array_of_displacements,
                                   MPI_Datatype oldtype,
                                   MPI_Datatype *newtype) {
  return multimpi_MPI_Type_indexed(count, array_of_blocklengths,
                                   array_of_displacements, oldtype, newtype);
}

int multimpi_MPI_Errhandler_create(MPI_Handler_function *function,
                                   MPI_Errhandler *errhandler);
static inline int MPI_Errhandler_create(MPI_Handler_function *function,
                                        MPI_Errhandler *errhandler) {
  return multimpi_MPI_Errhandler_create(function, errhandler);
}

int multimpi_MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                                  MPI_Comm peer_comm, int remote_leader,
                                  int tag, MPI_Comm *newintercomm);
static inline int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                                       MPI_Comm peer_comm, int remote_leader,
                                       int tag, MPI_Comm *newintercomm) {
  return multimpi_MPI_Intercomm_create(local_comm, local_leader, peer_comm,
                                       remote_leader, tag, newintercomm);
}

int multimpi_MPI_Type_lb(MPI_Datatype datatype, MPI_Aint *displacement);
static inline int MPI_Type_lb(MPI_Datatype datatype, MPI_Aint *displacement) {
  return multimpi_MPI_Type_lb(datatype, displacement);
}

int multimpi_MPI_Errhandler_free(MPI_Errhandler *errhandler);
static inline int MPI_Errhandler_free(MPI_Errhandler *errhandler) {
  return multimpi_MPI_Errhandler_free(errhandler);
}

int multimpi_MPI_Intercomm_merge(MPI_Comm intercomm, int high,
                                 MPI_Comm *newintracomm);
static inline int MPI_Intercomm_merge(MPI_Comm intercomm, int high,
                                      MPI_Comm *newintracomm) {
  return multimpi_MPI_Intercomm_merge(intercomm, high, newintracomm);
}

int multimpi_MPI_Type_match_size(int typeclass, int size,
                                 MPI_Datatype *datatype);
static inline int MPI_Type_match_size(int typeclass, int size,
                                      MPI_Datatype *datatype) {
  return multimpi_MPI_Type_match_size(typeclass, size, datatype);
}

int multimpi_MPI_Errhandler_get(MPI_Comm comm, MPI_Errhandler *errhandler);
static inline int MPI_Errhandler_get(MPI_Comm comm,
                                     MPI_Errhandler *errhandler) {
  return multimpi_MPI_Errhandler_get(comm, errhandler);
}

int multimpi_MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag,
                        MPI_Status *status);
static inline int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag,
                             MPI_Status *status) {
  return multimpi_MPI_Iprobe(source, tag, comm, flag, status);
}

int multimpi_MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval,
                               void *attribute_val);
static inline int MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval,
                                    void *attribute_val) {
  return multimpi_MPI_Type_set_attr(datatype, type_keyval, attribute_val);
}

int multimpi_MPI_Errhandler_set(MPI_Comm comm, MPI_Errhandler errhandler);
static inline int MPI_Errhandler_set(MPI_Comm comm, MPI_Errhandler errhandler) {
  return multimpi_MPI_Errhandler_set(comm, errhandler);
}

int multimpi_MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source,
                       int tag, MPI_Comm comm, MPI_Request *request);
static inline int MPI_Irecv(void *buf, int count, MPI_Datatype datatype,
                            int source, int tag, MPI_Comm comm,
                            MPI_Request *request) {
  return multimpi_MPI_Irecv(buf, count, datatype, source, tag, comm, request);
}

int multimpi_MPI_Type_set_name(MPI_Datatype datatype, const char *type_name);
static inline int MPI_Type_set_name(MPI_Datatype datatype,
                                    const char *type_name) {
  return multimpi_MPI_Type_set_name(datatype, type_name);
}

int multimpi_MPI_Error_class(int errorcode, int *errorclass);
static inline int MPI_Error_class(int errorcode, int *errorclass) {
  return multimpi_MPI_Error_class(errorcode, errorclass);
}

int multimpi_MPI_Ireduce(const void *sendbuf, void *recvbuf, int count,
                         MPI_Datatype datatype, MPI_Op op, int root,
                         MPI_Comm comm, MPI_Request *request);
static inline int MPI_Ireduce(const void *sendbuf, void *recvbuf, int count,
                              MPI_Datatype datatype, MPI_Op op, int root,
                              MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Ireduce(sendbuf, recvbuf, count, datatype, op, root, comm,
                              request);
}

int multimpi_MPI_Type_size(MPI_Datatype datatype, int *size);
static inline int MPI_Type_size(MPI_Datatype datatype, int *size) {
  return multimpi_MPI_Type_size(datatype, size);
}

int multimpi_MPI_Error_string(int errorcode, char *string, int *resultlen);
static inline int MPI_Error_string(int errorcode, char *string,
                                   int *resultlen) {
  return multimpi_MPI_Error_string(errorcode, string, resultlen);
}

int multimpi_MPI_Ireduce_scatter(const void *sendbuf, void *recvbuf,
                                 const int recvcounts[], MPI_Datatype datatype,
                                 MPI_Op op, MPI_Comm comm,
                                 MPI_Request *request);
static inline int MPI_Ireduce_scatter(const void *sendbuf, void *recvbuf,
                                      const int recvcounts[],
                                      MPI_Datatype datatype, MPI_Op op,
                                      MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype,
                                      op, comm, request);
}

int multimpi_MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size);
static inline int MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size) {
  return multimpi_MPI_Type_size_x(datatype, size);
}

int multimpi_MPI_Exscan(const void *sendbuf, void *recvbuf, int count,
                        MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
static inline int MPI_Exscan(const void *sendbuf, void *recvbuf, int count,
                             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return multimpi_MPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm);
}

int multimpi_MPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf,
                                       int recvcount, MPI_Datatype datatype,
                                       MPI_Op op, MPI_Comm comm,
                                       MPI_Request *request);
static inline int MPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf,
                                            int recvcount,
                                            MPI_Datatype datatype, MPI_Op op,
                                            MPI_Comm comm,
                                            MPI_Request *request) {
  return multimpi_MPI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount,
                                            datatype, op, comm, request);
}

int multimpi_MPI_Type_struct(int count, const int *array_of_blocklengths,
                             const MPI_Aint *array_of_displacements,
                             const MPI_Datatype *array_of_types,
                             MPI_Datatype *newtype);
static inline int MPI_Type_struct(int count, const int *array_of_blocklengths,
                                  const MPI_Aint *array_of_displacements,
                                  const MPI_Datatype *array_of_types,
                                  MPI_Datatype *newtype) {
  return multimpi_MPI_Type_struct(count, array_of_blocklengths,
                                  array_of_displacements, array_of_types,
                                  newtype);
}

int multimpi_MPI_Fetch_and_op(const void *origin_addr, void *result_addr,
                              MPI_Datatype datatype, int target_rank,
                              MPI_Aint target_disp, MPI_Op op, MPI_Win win);
static inline int MPI_Fetch_and_op(const void *origin_addr, void *result_addr,
                                   MPI_Datatype datatype, int target_rank,
                                   MPI_Aint target_disp, MPI_Op op,
                                   MPI_Win win) {
  return multimpi_MPI_Fetch_and_op(origin_addr, result_addr, datatype,
                                   target_rank, target_disp, op, win);
}

int multimpi_MPI_Irsend(const void *buf, int count, MPI_Datatype datatype,
                        int dest, int tag, MPI_Comm comm, MPI_Request *request);
static inline int MPI_Irsend(const void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm,
                             MPI_Request *request) {
  return multimpi_MPI_Irsend(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement);
static inline int MPI_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement) {
  return multimpi_MPI_Type_ub(datatype, displacement);
}

MPI_Fint multimpi_MPI_File_c2f(MPI_File fh);
static inline MPI_Fint MPI_File_c2f(MPI_File fh) {
  return multimpi_MPI_File_c2f(fh);
}

int multimpi_MPI_Is_thread_main(int *flag);
static inline int MPI_Is_thread_main(int *flag) {
  return multimpi_MPI_Is_thread_main(flag);
}

int multimpi_MPI_Type_vector(int count, int blocklength, int stride,
                             MPI_Datatype oldtype, MPI_Datatype *newtype);
static inline int MPI_Type_vector(int count, int blocklength, int stride,
                                  MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return multimpi_MPI_Type_vector(count, blocklength, stride, oldtype, newtype);
}

int multimpi_MPI_File_call_errhandler(MPI_File fh, int errorcode);
static inline int MPI_File_call_errhandler(MPI_File fh, int errorcode) {
  return multimpi_MPI_File_call_errhandler(fh, errorcode);
}

int multimpi_MPI_Iscan(const void *sendbuf, void *recvbuf, int count,
                       MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                       MPI_Request *request);
static inline int MPI_Iscan(const void *sendbuf, void *recvbuf, int count,
                            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                            MPI_Request *request) {
  return multimpi_MPI_Iscan(sendbuf, recvbuf, count, datatype, op, comm,
                            request);
}

int multimpi_MPI_Unpack(const void *inbuf, int insize, int *position,
                        void *outbuf, int outcount, MPI_Datatype datatype,
                        MPI_Comm comm);
static inline int MPI_Unpack(const void *inbuf, int insize, int *position,
                             void *outbuf, int outcount, MPI_Datatype datatype,
                             MPI_Comm comm) {
  return multimpi_MPI_Unpack(inbuf, insize, position, outbuf, outcount,
                             datatype, comm);
}

int multimpi_MPI_File_close(MPI_File *fh);
static inline int MPI_File_close(MPI_File *fh) {
  return multimpi_MPI_File_close(fh);
}

int multimpi_MPI_Iscatter(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf, int recvcount,
                          MPI_Datatype recvtype, int root, MPI_Comm comm,
                          MPI_Request *request);
static inline int MPI_Iscatter(const void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               int recvcount, MPI_Datatype recvtype, int root,
                               MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                               recvtype, root, comm, request);
}

int multimpi_MPI_Unpack_external(const char datarep[], const void *inbuf,
                                 MPI_Aint insize, MPI_Aint *position,
                                 void *outbuf, int outcount,
                                 MPI_Datatype datatype);
static inline int MPI_Unpack_external(const char datarep[], const void *inbuf,
                                      MPI_Aint insize, MPI_Aint *position,
                                      void *outbuf, int outcount,
                                      MPI_Datatype datatype) {
  return multimpi_MPI_Unpack_external(datarep, inbuf, insize, position, outbuf,
                                      outcount, datatype);
}

int multimpi_MPI_File_create_errhandler(
    MPI_File_errhandler_function *file_errhandler_fn,
    MPI_Errhandler *errhandler);
static inline int
MPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn,
                           MPI_Errhandler *errhandler) {
  return multimpi_MPI_File_create_errhandler(file_errhandler_fn, errhandler);
}

int multimpi_MPI_Iscatterv(const void *sendbuf, const int sendcounts[],
                           const int displs[], MPI_Datatype sendtype,
                           void *recvbuf, int recvcount, MPI_Datatype recvtype,
                           int root, MPI_Comm comm, MPI_Request *request);
static inline int MPI_Iscatterv(const void *sendbuf, const int sendcounts[],
                                const int displs[], MPI_Datatype sendtype,
                                void *recvbuf, int recvcount,
                                MPI_Datatype recvtype, int root, MPI_Comm comm,
                                MPI_Request *request) {
  return multimpi_MPI_Iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                recvcount, recvtype, root, comm, request);
}

int multimpi_MPI_Unpublish_name(const char *service_name, MPI_Info info,
                                const char *port_name);
static inline int MPI_Unpublish_name(const char *service_name, MPI_Info info,
                                     const char *port_name) {
  return multimpi_MPI_Unpublish_name(service_name, info, port_name);
}

int multimpi_MPI_File_delete(char *filename, MPI_Info info);
static inline int MPI_File_delete(char *filename, MPI_Info info) {
  return multimpi_MPI_File_delete(filename, info);
}

int multimpi_MPI_Isend(const void *buf, int count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm, MPI_Request *request);
static inline int MPI_Isend(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm,
                            MPI_Request *request) {
  return multimpi_MPI_Isend(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Wait(MPI_Request *request, MPI_Status *status);
static inline int MPI_Wait(MPI_Request *request, MPI_Status *status) {
  return multimpi_MPI_Wait(request, status);
}

MPI_File multimpi_MPI_File_f2c(MPI_Fint fh);
static inline MPI_File MPI_File_f2c(MPI_Fint fh) {
  return multimpi_MPI_File_f2c(fh);
}

int multimpi_MPI_Issend(const void *buf, int count, MPI_Datatype datatype,
                        int dest, int tag, MPI_Comm comm, MPI_Request *request);
static inline int MPI_Issend(const void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm,
                             MPI_Request *request) {
  return multimpi_MPI_Issend(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Waitall(int count, MPI_Request array_of_requests[],
                         MPI_Status array_of_statuses[]);
static inline int MPI_Waitall(int count, MPI_Request array_of_requests[],
                              MPI_Status array_of_statuses[]) {
  return multimpi_MPI_Waitall(count, array_of_requests, array_of_statuses);
}

int multimpi_MPI_File_get_amode(MPI_File fh, int *amode);
static inline int MPI_File_get_amode(MPI_File fh, int *amode) {
  return multimpi_MPI_File_get_amode(fh, amode);
}

int multimpi_MPI_Keyval_create(MPI_Copy_function *copy_fn,
                               MPI_Delete_function *delete_fn, int *keyval,
                               void *extra_state);
static inline int MPI_Keyval_create(MPI_Copy_function *copy_fn,
                                    MPI_Delete_function *delete_fn, int *keyval,
                                    void *extra_state) {
  return multimpi_MPI_Keyval_create(copy_fn, delete_fn, keyval, extra_state);
}

int multimpi_MPI_Waitany(int count, MPI_Request array_of_requests[], int *indx,
                         MPI_Status *status);
static inline int MPI_Waitany(int count, MPI_Request array_of_requests[],
                              int *indx, MPI_Status *status) {
  return multimpi_MPI_Waitany(count, array_of_requests, indx, status);
}

int multimpi_MPI_File_get_atomicity(MPI_File fh, int *flag);
static inline int MPI_File_get_atomicity(MPI_File fh, int *flag) {
  return multimpi_MPI_File_get_atomicity(fh, flag);
}

int multimpi_MPI_Keyval_free(int *keyval);
static inline int MPI_Keyval_free(int *keyval) {
  return multimpi_MPI_Keyval_free(keyval);
}

int multimpi_MPI_Waitsome(int incount, MPI_Request array_of_requests[],
                          int *outcount, int array_of_indices[],
                          MPI_Status array_of_statuses[]);
static inline int MPI_Waitsome(int incount, MPI_Request array_of_requests[],
                               int *outcount, int array_of_indices[],
                               MPI_Status array_of_statuses[]) {
  return multimpi_MPI_Waitsome(incount, array_of_requests, outcount,
                               array_of_indices, array_of_statuses);
}

int multimpi_MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset,
                                      MPI_Offset *disp);
static inline int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset,
                                           MPI_Offset *disp) {
  return multimpi_MPI_File_get_byte_offset(fh, offset, disp);
}

int multimpi_MPI_Lookup_name(const char *service_name, MPI_Info info,
                             char *port_name);
static inline int MPI_Lookup_name(const char *service_name, MPI_Info info,
                                  char *port_name) {
  return multimpi_MPI_Lookup_name(service_name, info, port_name);
}

int multimpi_MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info,
                              MPI_Comm comm, void *baseptr, MPI_Win *win);
static inline int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info,
                                   MPI_Comm comm, void *baseptr, MPI_Win *win) {
  return multimpi_MPI_Win_allocate(size, disp_unit, info, comm, baseptr, win);
}

int multimpi_MPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler);
static inline int MPI_File_get_errhandler(MPI_File file,
                                          MPI_Errhandler *errhandler) {
  return multimpi_MPI_File_get_errhandler(file, errhandler);
}

int multimpi_MPI_Mprobe(int source, int tag, MPI_Comm comm,
                        MPI_Message *message, MPI_Status *status);
static inline int MPI_Mprobe(int source, int tag, MPI_Comm comm,
                             MPI_Message *message, MPI_Status *status) {
  return multimpi_MPI_Mprobe(source, tag, comm, message, status);
}

int multimpi_MPI_Win_allocate_shared(MPI_Aint size, int disp_unit,
                                     MPI_Info info, MPI_Comm comm,
                                     void *baseptr, MPI_Win *win);
static inline int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit,
                                          MPI_Info info, MPI_Comm comm,
                                          void *baseptr, MPI_Win *win) {
  return multimpi_MPI_Win_allocate_shared(size, disp_unit, info, comm, baseptr,
                                          win);
}

int multimpi_MPI_File_get_group(MPI_File fh, MPI_Group *group);
static inline int MPI_File_get_group(MPI_File fh, MPI_Group *group) {
  return multimpi_MPI_File_get_group(fh, group);
}

int multimpi_MPI_Mrecv(void *buf, int count, MPI_Datatype datatype,
                       MPI_Message *message, MPI_Status *status);
static inline int MPI_Mrecv(void *buf, int count, MPI_Datatype datatype,
                            MPI_Message *message, MPI_Status *status) {
  return multimpi_MPI_Mrecv(buf, count, datatype, message, status);
}

int multimpi_MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size);
static inline int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size) {
  return multimpi_MPI_Win_attach(win, base, size);
}

int multimpi_MPI_File_get_info(MPI_File fh, MPI_Info *info_used);
static inline int MPI_File_get_info(MPI_File fh, MPI_Info *info_used) {
  return multimpi_MPI_File_get_info(fh, info_used);
}

int multimpi_MPI_Neighbor_allgather(const void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    int recvcount, MPI_Datatype recvtype,
                                    MPI_Comm comm);
static inline int MPI_Neighbor_allgather(const void *sendbuf, int sendcount,
                                         MPI_Datatype sendtype, void *recvbuf,
                                         int recvcount, MPI_Datatype recvtype,
                                         MPI_Comm comm) {
  return multimpi_MPI_Neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf,
                                         recvcount, recvtype, comm);
}

int multimpi_MPI_Win_call_errhandler(MPI_Win win, int errorcode);
static inline int MPI_Win_call_errhandler(MPI_Win win, int errorcode) {
  return multimpi_MPI_Win_call_errhandler(win, errorcode);
}

int multimpi_MPI_File_get_position(MPI_File fh, MPI_Offset *offset);
static inline int MPI_File_get_position(MPI_File fh, MPI_Offset *offset) {
  return multimpi_MPI_File_get_position(fh, offset);
}

int multimpi_MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     const int recvcounts[], const int displs[],
                                     MPI_Datatype recvtype, MPI_Comm comm);
static inline int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount,
                                          MPI_Datatype sendtype, void *recvbuf,
                                          const int recvcounts[],
                                          const int displs[],
                                          MPI_Datatype recvtype,
                                          MPI_Comm comm) {
  return multimpi_MPI_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf,
                                          recvcounts, displs, recvtype, comm);
}

int multimpi_MPI_Win_complete(MPI_Win win);
static inline int MPI_Win_complete(MPI_Win win) {
  return multimpi_MPI_Win_complete(win);
}

int multimpi_MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset);
static inline int MPI_File_get_position_shared(MPI_File fh,
                                               MPI_Offset *offset) {
  return multimpi_MPI_File_get_position_shared(fh, offset);
}

int multimpi_MPI_Neighbor_alltoall(const void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   int recvcount, MPI_Datatype recvtype,
                                   MPI_Comm comm);
static inline int MPI_Neighbor_alltoall(const void *sendbuf, int sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        int recvcount, MPI_Datatype recvtype,
                                        MPI_Comm comm) {
  return multimpi_MPI_Neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf,
                                        recvcount, recvtype, comm);
}

int multimpi_MPI_Win_create(void *base, MPI_Aint size, int disp_unit,
                            MPI_Info info, MPI_Comm comm, MPI_Win *win);
static inline int MPI_Win_create(void *base, MPI_Aint size, int disp_unit,
                                 MPI_Info info, MPI_Comm comm, MPI_Win *win) {
  return multimpi_MPI_Win_create(base, size, disp_unit, info, comm, win);
}

int multimpi_MPI_File_get_size(MPI_File fh, MPI_Offset *size);
static inline int MPI_File_get_size(MPI_File fh, MPI_Offset *size) {
  return multimpi_MPI_File_get_size(fh, size);
}

int multimpi_MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                                    const int sdispls[], MPI_Datatype sendtype,
                                    void *recvbuf, const int recvcounts[],
                                    const int rdispls[], MPI_Datatype recvtype,
                                    MPI_Comm comm);
static inline int MPI_Neighbor_alltoallv(
    const void *sendbuf, const int sendcounts[], const int sdispls[],
    MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
    const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm) {
  return multimpi_MPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype,
                                         recvbuf, recvcounts, rdispls, recvtype,
                                         comm);
}

int multimpi_MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win);
static inline int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm,
                                         MPI_Win *win) {
  return multimpi_MPI_Win_create_dynamic(info, comm, win);
}

int multimpi_MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype,
                                      MPI_Aint *extent);
static inline int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype,
                                           MPI_Aint *extent) {
  return multimpi_MPI_File_get_type_extent(fh, datatype, extent);
}

int multimpi_MPI_Neighbor_alltoallw(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm);
static inline int MPI_Neighbor_alltoallw(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) {
  return multimpi_MPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls,
                                         sendtypes, recvbuf, recvcounts,
                                         rdispls, recvtypes, comm);
}

int multimpi_MPI_Win_create_errhandler(
    MPI_Win_errhandler_function *win_errhandler_fn, MPI_Errhandler *errhandler);
static inline int
MPI_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn,
                          MPI_Errhandler *errhandler) {
  return multimpi_MPI_Win_create_errhandler(win_errhandler_fn, errhandler);
}

int multimpi_MPI_File_get_view(MPI_File fh, MPI_Offset *disp,
                               MPI_Datatype *etype, MPI_Datatype *filetype,
                               char *datarep);
static inline int MPI_File_get_view(MPI_File fh, MPI_Offset *disp,
                                    MPI_Datatype *etype, MPI_Datatype *filetype,
                                    char *datarep) {
  return multimpi_MPI_File_get_view(fh, disp, etype, filetype, datarep);
}

int multimpi_MPI_Op_commutative(MPI_Op op, int *commute);
static inline int MPI_Op_commutative(MPI_Op op, int *commute) {
  return multimpi_MPI_Op_commutative(op, commute);
}

int multimpi_MPI_Win_create_keyval(
    MPI_Win_copy_attr_function *win_copy_attr_fn,
    MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
    void *extra_state);
static inline int
MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn,
                      MPI_Win_delete_attr_function *win_delete_attr_fn,
                      int *win_keyval, void *extra_state) {
  return multimpi_MPI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn,
                                        win_keyval, extra_state);
}

int multimpi_MPI_File_iread(MPI_File fh, void *buf, int count,
                            MPI_Datatype datatype, MPI_Request *request);
static inline int MPI_File_iread(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype, MPI_Request *request) {
  return multimpi_MPI_File_iread(fh, buf, count, datatype, request);
}

int multimpi_MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op);
static inline int MPI_Op_create(MPI_User_function *user_fn, int commute,
                                MPI_Op *op) {
  return multimpi_MPI_Op_create(user_fn, commute, op);
}

int multimpi_MPI_Win_delete_attr(MPI_Win win, int win_keyval);
static inline int MPI_Win_delete_attr(MPI_Win win, int win_keyval) {
  return multimpi_MPI_Win_delete_attr(win, win_keyval);
}

int multimpi_MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf,
                               int count, MPI_Datatype datatype,
                               MPIO_Request *request);
static inline int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf,
                                    int count, MPI_Datatype datatype,
                                    MPIO_Request *request) {
  return multimpi_MPI_File_iread_at(fh, offset, buf, count, datatype, request);
}

int multimpi_MPI_Op_free(MPI_Op *op);
static inline int MPI_Op_free(MPI_Op *op) { return multimpi_MPI_Op_free(op); }

int multimpi_MPI_Win_detach(MPI_Win win, const void *base);
static inline int MPI_Win_detach(MPI_Win win, const void *base) {
  return multimpi_MPI_Win_detach(win, base);
}

int multimpi_MPI_File_iread_shared(MPI_File fh, void *buf, int count,
                                   MPI_Datatype datatype, MPI_Request *request);
static inline int MPI_File_iread_shared(MPI_File fh, void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Request *request) {
  return multimpi_MPI_File_iread_shared(fh, buf, count, datatype, request);
}

int multimpi_MPI_Open_port(MPI_Info info, char *port_name);
static inline int MPI_Open_port(MPI_Info info, char *port_name) {
  return multimpi_MPI_Open_port(info, port_name);
}

int multimpi_MPI_Win_fence(int assert, MPI_Win win);
static inline int MPI_Win_fence(int assert, MPI_Win win) {
  return multimpi_MPI_Win_fence(assert, win);
}

int multimpi_MPI_File_iwrite(MPI_File fh, void *buf, int count,
                             MPI_Datatype datatype, MPI_Request *request);
static inline int MPI_File_iwrite(MPI_File fh, void *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request) {
  return multimpi_MPI_File_iwrite(fh, buf, count, datatype, request);
}

int multimpi_MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype,
                      void *outbuf, int outsize, int *position, MPI_Comm comm);
static inline int MPI_Pack(const void *inbuf, int incount,
                           MPI_Datatype datatype, void *outbuf, int outsize,
                           int *position, MPI_Comm comm) {
  return multimpi_MPI_Pack(inbuf, incount, datatype, outbuf, outsize, position,
                           comm);
}

int multimpi_MPI_Win_flush(int rank, MPI_Win win);
static inline int MPI_Win_flush(int rank, MPI_Win win) {
  return multimpi_MPI_Win_flush(rank, win);
}

int multimpi_MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, void *buf,
                                int count, MPI_Datatype datatype,
                                MPIO_Request *request);
static inline int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, void *buf,
                                     int count, MPI_Datatype datatype,
                                     MPIO_Request *request) {
  return multimpi_MPI_File_iwrite_at(fh, offset, buf, count, datatype, request);
}

int multimpi_MPI_Pack_external(const char datarep[], const void *inbuf,
                               int incount, MPI_Datatype datatype, void *outbuf,
                               MPI_Aint outsize, MPI_Aint *position);
static inline int MPI_Pack_external(const char datarep[], const void *inbuf,
                                    int incount, MPI_Datatype datatype,
                                    void *outbuf, MPI_Aint outsize,
                                    MPI_Aint *position) {
  return multimpi_MPI_Pack_external(datarep, inbuf, incount, datatype, outbuf,
                                    outsize, position);
}

int multimpi_MPI_Win_flush_all(MPI_Win win);
static inline int MPI_Win_flush_all(MPI_Win win) {
  return multimpi_MPI_Win_flush_all(win);
}

int multimpi_MPI_File_iwrite_shared(MPI_File fh, void *buf, int count,
                                    MPI_Datatype datatype,
                                    MPIO_Request *request);
static inline int MPI_File_iwrite_shared(MPI_File fh, void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPIO_Request *request) {
  return multimpi_MPI_File_iwrite_shared(fh, buf, count, datatype, request);
}

int multimpi_MPI_Pack_external_size(const char datarep[], int incount,
                                    MPI_Datatype datatype, MPI_Aint *size);
static inline int MPI_Pack_external_size(const char datarep[], int incount,
                                         MPI_Datatype datatype,
                                         MPI_Aint *size) {
  return multimpi_MPI_Pack_external_size(datarep, incount, datatype, size);
}

int multimpi_MPI_Win_flush_local(int rank, MPI_Win win);
static inline int MPI_Win_flush_local(int rank, MPI_Win win) {
  return multimpi_MPI_Win_flush_local(rank, win);
}

int multimpi_MPI_File_open(MPI_Comm comm, char *filename, int amode,
                           MPI_Info info, MPI_File *fh);
static inline int MPI_File_open(MPI_Comm comm, char *filename, int amode,
                                MPI_Info info, MPI_File *fh) {
  return multimpi_MPI_File_open(comm, filename, amode, info, fh);
}

int multimpi_MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm,
                           int *size);
static inline int MPI_Pack_size(int incount, MPI_Datatype datatype,
                                MPI_Comm comm, int *size) {
  return multimpi_MPI_Pack_size(incount, datatype, comm, size);
}

int multimpi_MPI_Win_flush_local_all(MPI_Win win);
static inline int MPI_Win_flush_local_all(MPI_Win win) {
  return multimpi_MPI_Win_flush_local_all(win);
}

int multimpi_MPI_File_preallocate(MPI_File fh, MPI_Offset size);
static inline int MPI_File_preallocate(MPI_File fh, MPI_Offset size) {
  return multimpi_MPI_File_preallocate(fh, size);
}

int multimpi_MPI_Win_free(MPI_Win *win);
static inline int MPI_Win_free(MPI_Win *win) {
  return multimpi_MPI_Win_free(win);
}

int multimpi_MPI_File_read(MPI_File fh, void *buf, int count,
                           MPI_Datatype datatype, MPI_Status *status);
static inline int MPI_File_read(MPI_File fh, void *buf, int count,
                                MPI_Datatype datatype, MPI_Status *status) {
  return multimpi_MPI_File_read(fh, buf, count, datatype, status);
}

int multimpi_MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status);
static inline int MPI_Probe(int source, int tag, MPI_Comm comm,
                            MPI_Status *status) {
  return multimpi_MPI_Probe(source, tag, comm, status);
}

int multimpi_MPI_Win_free_keyval(int *win_keyval);
static inline int MPI_Win_free_keyval(int *win_keyval) {
  return multimpi_MPI_Win_free_keyval(win_keyval);
}

int multimpi_MPI_File_read_all(MPI_File fh, void *buf, int count,
                               MPI_Datatype datatype, MPI_Status *status);
static inline int MPI_File_read_all(MPI_File fh, void *buf, int count,
                                    MPI_Datatype datatype, MPI_Status *status) {
  return multimpi_MPI_File_read_all(fh, buf, count, datatype, status);
}

int multimpi_MPI_Publish_name(const char *service_name, MPI_Info info,
                              const char *port_name);
static inline int MPI_Publish_name(const char *service_name, MPI_Info info,
                                   const char *port_name) {
  return multimpi_MPI_Publish_name(service_name, info, port_name);
}

int multimpi_MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val,
                              int *flag);
static inline int MPI_Win_get_attr(MPI_Win win, int win_keyval,
                                   void *attribute_val, int *flag) {
  return multimpi_MPI_Win_get_attr(win, win_keyval, attribute_val, flag);
}

int multimpi_MPI_File_read_all_begin(MPI_File fh, void *buf, int count,
                                     MPI_Datatype datatype);
static inline int MPI_File_read_all_begin(MPI_File fh, void *buf, int count,
                                          MPI_Datatype datatype) {
  return multimpi_MPI_File_read_all_begin(fh, buf, count, datatype);
}

int multimpi_MPI_Put(const void *origin_addr, int origin_count,
                     MPI_Datatype origin_datatype, int target_rank,
                     MPI_Aint target_disp, int target_count,
                     MPI_Datatype target_datatype, MPI_Win win);
static inline int MPI_Put(const void *origin_addr, int origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, int target_count,
                          MPI_Datatype target_datatype, MPI_Win win) {
  return multimpi_MPI_Put(origin_addr, origin_count, origin_datatype,
                          target_rank, target_disp, target_count,
                          target_datatype, win);
}

int multimpi_MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler);
static inline int MPI_Win_get_errhandler(MPI_Win win,
                                         MPI_Errhandler *errhandler) {
  return multimpi_MPI_Win_get_errhandler(win, errhandler);
}

int multimpi_MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status);
static inline int MPI_File_read_all_end(MPI_File fh, void *buf,
                                        MPI_Status *status) {
  return multimpi_MPI_File_read_all_end(fh, buf, status);
}

int multimpi_MPI_Query_thread(int *provided);
static inline int MPI_Query_thread(int *provided) {
  return multimpi_MPI_Query_thread(provided);
}

int multimpi_MPI_Win_get_group(MPI_Win win, MPI_Group *group);
static inline int MPI_Win_get_group(MPI_Win win, MPI_Group *group) {
  return multimpi_MPI_Win_get_group(win, group);
}

int multimpi_MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf,
                              int count, MPI_Datatype datatype,
                              MPI_Status *status);
static inline int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf,
                                   int count, MPI_Datatype datatype,
                                   MPI_Status *status) {
  return multimpi_MPI_File_read_at(fh, offset, buf, count, datatype, status);
}

int multimpi_MPI_Raccumulate(const void *origin_addr, int origin_count,
                             MPI_Datatype origin_datatype, int target_rank,
                             MPI_Aint target_disp, int target_count,
                             MPI_Datatype target_datatype, MPI_Op op,
                             MPI_Win win, MPI_Request *request);
static inline int MPI_Raccumulate(const void *origin_addr, int origin_count,
                                  MPI_Datatype origin_datatype, int target_rank,
                                  MPI_Aint target_disp, int target_count,
                                  MPI_Datatype target_datatype, MPI_Op op,
                                  MPI_Win win, MPI_Request *request) {
  return multimpi_MPI_Raccumulate(origin_addr, origin_count, origin_datatype,
                                  target_rank, target_disp, target_count,
                                  target_datatype, op, win, request);
}

int multimpi_MPI_Win_get_info(MPI_Win win, MPI_Info *info_used);
static inline int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used) {
  return multimpi_MPI_Win_get_info(win, info_used);
}

int multimpi_MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf,
                                  int count, MPI_Datatype datatype,
                                  MPI_Status *status);
static inline int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset,
                                       void *buf, int count,
                                       MPI_Datatype datatype,
                                       MPI_Status *status) {
  return multimpi_MPI_File_read_at_all(fh, offset, buf, count, datatype,
                                       status);
}

int multimpi_MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source,
                      int tag, MPI_Comm comm, MPI_Status *status);
static inline int MPI_Recv(void *buf, int count, MPI_Datatype datatype,
                           int source, int tag, MPI_Comm comm,
                           MPI_Status *status) {
  return multimpi_MPI_Recv(buf, count, datatype, source, tag, comm, status);
}

int multimpi_MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen);
static inline int MPI_Win_get_name(MPI_Win win, char *win_name,
                                   int *resultlen) {
  return multimpi_MPI_Win_get_name(win, win_name, resultlen);
}

int multimpi_MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset,
                                        void *buf, int count,
                                        MPI_Datatype datatype);
static inline int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset,
                                             void *buf, int count,
                                             MPI_Datatype datatype) {
  return multimpi_MPI_File_read_at_all_begin(fh, offset, buf, count, datatype);
}

int multimpi_MPI_Recv_init(void *buf, int count, MPI_Datatype datatype,
                           int source, int tag, MPI_Comm comm,
                           MPI_Request *request);
static inline int MPI_Recv_init(void *buf, int count, MPI_Datatype datatype,
                                int source, int tag, MPI_Comm comm,
                                MPI_Request *request) {
  return multimpi_MPI_Recv_init(buf, count, datatype, source, tag, comm,
                                request);
}

int multimpi_MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win);
static inline int MPI_Win_lock(int lock_type, int rank, int assert,
                               MPI_Win win) {
  return multimpi_MPI_Win_lock(lock_type, rank, assert, win);
}

int multimpi_MPI_File_read_at_all_end(MPI_File fh, void *buf,
                                      MPI_Status *status);
static inline int MPI_File_read_at_all_end(MPI_File fh, void *buf,
                                           MPI_Status *status) {
  return multimpi_MPI_File_read_at_all_end(fh, buf, status);
}

int multimpi_MPI_Reduce(const void *sendbuf, void *recvbuf, int count,
                        MPI_Datatype datatype, MPI_Op op, int root,
                        MPI_Comm comm);
static inline int MPI_Reduce(const void *sendbuf, void *recvbuf, int count,
                             MPI_Datatype datatype, MPI_Op op, int root,
                             MPI_Comm comm) {
  return multimpi_MPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm);
}

int multimpi_MPI_Win_lock_all(int assert, MPI_Win win);
static inline int MPI_Win_lock_all(int assert, MPI_Win win) {
  return multimpi_MPI_Win_lock_all(assert, win);
}

int multimpi_MPI_File_read_ordered(MPI_File fh, void *buf, int count,
                                   MPI_Datatype datatype, MPI_Status *status);
static inline int MPI_File_read_ordered(MPI_File fh, void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Status *status) {
  return multimpi_MPI_File_read_ordered(fh, buf, count, datatype, status);
}

int multimpi_MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count,
                              MPI_Datatype datatype, MPI_Op op);
static inline int MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count,
                                   MPI_Datatype datatype, MPI_Op op) {
  return multimpi_MPI_Reduce_local(inbuf, inoutbuf, count, datatype, op);
}

int multimpi_MPI_Win_post(MPI_Group group, int assert, MPI_Win win);
static inline int MPI_Win_post(MPI_Group group, int assert, MPI_Win win) {
  return multimpi_MPI_Win_post(group, assert, win);
}

int multimpi_MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count,
                                         MPI_Datatype datatype);
static inline int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count,
                                              MPI_Datatype datatype) {
  return multimpi_MPI_File_read_ordered_begin(fh, buf, count, datatype);
}

int multimpi_MPI_Reduce_scatter(const void *sendbuf, void *recvbuf,
                                const int recvcounts[], MPI_Datatype datatype,
                                MPI_Op op, MPI_Comm comm);
static inline int MPI_Reduce_scatter(const void *sendbuf, void *recvbuf,
                                     const int recvcounts[],
                                     MPI_Datatype datatype, MPI_Op op,
                                     MPI_Comm comm) {
  return multimpi_MPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op,
                                     comm);
}

int multimpi_MPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val);
static inline int MPI_Win_set_attr(MPI_Win win, int win_keyval,
                                   void *attribute_val) {
  return multimpi_MPI_Win_set_attr(win, win_keyval, attribute_val);
}

int multimpi_MPI_File_read_ordered_end(MPI_File fh, void *buf,
                                       MPI_Status *status);
static inline int MPI_File_read_ordered_end(MPI_File fh, void *buf,
                                            MPI_Status *status) {
  return multimpi_MPI_File_read_ordered_end(fh, buf, status);
}

int multimpi_MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf,
                                      int recvcount, MPI_Datatype datatype,
                                      MPI_Op op, MPI_Comm comm);
static inline int MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf,
                                           int recvcount, MPI_Datatype datatype,
                                           MPI_Op op, MPI_Comm comm) {
  return multimpi_MPI_Reduce_scatter_block(sendbuf, recvbuf, recvcount,
                                           datatype, op, comm);
}

int multimpi_MPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler);
static inline int MPI_Win_set_errhandler(MPI_Win win,
                                         MPI_Errhandler errhandler) {
  return multimpi_MPI_Win_set_errhandler(win, errhandler);
}

int multimpi_MPI_File_read_shared(MPI_File fh, void *buf, int count,
                                  MPI_Datatype datatype, MPI_Status *status);
static inline int MPI_File_read_shared(MPI_File fh, void *buf, int count,
                                       MPI_Datatype datatype,
                                       MPI_Status *status) {
  return multimpi_MPI_File_read_shared(fh, buf, count, datatype, status);
}

int multimpi_MPI_Register_datarep(
    char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
    MPI_Datarep_conversion_function *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);
static inline int MPI_Register_datarep(
    char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
    MPI_Datarep_conversion_function *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) {
  return multimpi_MPI_Register_datarep(datarep, read_conversion_fn,
                                       write_conversion_fn,
                                       dtype_file_extent_fn, extra_state);
}

int multimpi_MPI_Win_set_info(MPI_Win win, MPI_Info info);
static inline int MPI_Win_set_info(MPI_Win win, MPI_Info info) {
  return multimpi_MPI_Win_set_info(win, info);
}

int multimpi_MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence);
static inline int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence) {
  return multimpi_MPI_File_seek(fh, offset, whence);
}

int multimpi_MPI_Request_free(MPI_Request *request);
static inline int MPI_Request_free(MPI_Request *request) {
  return multimpi_MPI_Request_free(request);
}

int multimpi_MPI_Win_set_name(MPI_Win win, const char *win_name);
static inline int MPI_Win_set_name(MPI_Win win, const char *win_name) {
  return multimpi_MPI_Win_set_name(win, win_name);
}

int multimpi_MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence);
static inline int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset,
                                       int whence) {
  return multimpi_MPI_File_seek_shared(fh, offset, whence);
}

int multimpi_MPI_Request_get_status(MPI_Request request, int *flag,
                                    MPI_Status *status);
static inline int MPI_Request_get_status(MPI_Request request, int *flag,
                                         MPI_Status *status) {
  return multimpi_MPI_Request_get_status(request, flag, status);
}

int multimpi_MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size,
                                  int *disp_unit, void *baseptr);
static inline int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size,
                                       int *disp_unit, void *baseptr) {
  return multimpi_MPI_Win_shared_query(win, rank, size, disp_unit, baseptr);
}

int multimpi_MPI_File_set_atomicity(MPI_File fh, int flag);
static inline int MPI_File_set_atomicity(MPI_File fh, int flag) {
  return multimpi_MPI_File_set_atomicity(fh, flag);
}

int multimpi_MPI_Rget(void *origin_addr, int origin_count,
                      MPI_Datatype origin_datatype, int target_rank,
                      MPI_Aint target_disp, int target_count,
                      MPI_Datatype target_datatype, MPI_Win win,
                      MPI_Request *request);
static inline int MPI_Rget(void *origin_addr, int origin_count,
                           MPI_Datatype origin_datatype, int target_rank,
                           MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, MPI_Win win,
                           MPI_Request *request) {
  return multimpi_MPI_Rget(origin_addr, origin_count, origin_datatype,
                           target_rank, target_disp, target_count,
                           target_datatype, win, request);
}

int multimpi_MPI_Win_start(MPI_Group group, int assert, MPI_Win win);
static inline int MPI_Win_start(MPI_Group group, int assert, MPI_Win win) {
  return multimpi_MPI_Win_start(group, assert, win);
}

int multimpi_MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler);
static inline int MPI_File_set_errhandler(MPI_File file,
                                          MPI_Errhandler errhandler) {
  return multimpi_MPI_File_set_errhandler(file, errhandler);
}

int multimpi_MPI_Rget_accumulate(const void *origin_addr, int origin_count,
                                 MPI_Datatype origin_datatype,
                                 void *result_addr, int result_count,
                                 MPI_Datatype result_datatype, int target_rank,
                                 MPI_Aint target_disp, int target_count,
                                 MPI_Datatype target_datatype, MPI_Op op,
                                 MPI_Win win, MPI_Request *request);
static inline int MPI_Rget_accumulate(const void *origin_addr, int origin_count,
                                      MPI_Datatype origin_datatype,
                                      void *result_addr, int result_count,
                                      MPI_Datatype result_datatype,
                                      int target_rank, MPI_Aint target_disp,
                                      int target_count,
                                      MPI_Datatype target_datatype, MPI_Op op,
                                      MPI_Win win, MPI_Request *request) {
  return multimpi_MPI_Rget_accumulate(
      origin_addr, origin_count, origin_datatype, result_addr, result_count,
      result_datatype, target_rank, target_disp, target_count, target_datatype,
      op, win, request);
}

int multimpi_MPI_Win_sync(MPI_Win win);
static inline int MPI_Win_sync(MPI_Win win) {
  return multimpi_MPI_Win_sync(win);
}

int multimpi_MPI_File_set_info(MPI_File fh, MPI_Info info);
static inline int MPI_File_set_info(MPI_File fh, MPI_Info info) {
  return multimpi_MPI_File_set_info(fh, info);
}

int multimpi_MPI_Rput(const void *origin_addr, int origin_count,
                      MPI_Datatype origin_datatype, int target_rank,
                      MPI_Aint target_disp, int target_count,
                      MPI_Datatype target_datatype, MPI_Win win,
                      MPI_Request *request);
static inline int MPI_Rput(const void *origin_addr, int origin_count,
                           MPI_Datatype origin_datatype, int target_rank,
                           MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, MPI_Win win,
                           MPI_Request *request) {
  return multimpi_MPI_Rput(origin_addr, origin_count, origin_datatype,
                           target_rank, target_disp, target_count,
                           target_datatype, win, request);
}

int multimpi_MPI_Win_test(MPI_Win win, int *flag);
static inline int MPI_Win_test(MPI_Win win, int *flag) {
  return multimpi_MPI_Win_test(win, flag);
}

int multimpi_MPI_File_set_size(MPI_File fh, MPI_Offset size);
static inline int MPI_File_set_size(MPI_File fh, MPI_Offset size) {
  return multimpi_MPI_File_set_size(fh, size);
}

int multimpi_MPI_Rsend(const void *buf, int count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm);
static inline int MPI_Rsend(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm) {
  return multimpi_MPI_Rsend(buf, count, datatype, dest, tag, comm);
}

int multimpi_MPI_Win_unlock(int rank, MPI_Win win);
static inline int MPI_Win_unlock(int rank, MPI_Win win) {
  return multimpi_MPI_Win_unlock(rank, win);
}

int multimpi_MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype,
                               MPI_Datatype filetype, char *datarep,
                               MPI_Info info);
static inline int MPI_File_set_view(MPI_File fh, MPI_Offset disp,
                                    MPI_Datatype etype, MPI_Datatype filetype,
                                    char *datarep, MPI_Info info) {
  return multimpi_MPI_File_set_view(fh, disp, etype, filetype, datarep, info);
}

int multimpi_MPI_Rsend_init(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm,
                            MPI_Request *request);
static inline int MPI_Rsend_init(const void *buf, int count,
                                 MPI_Datatype datatype, int dest, int tag,
                                 MPI_Comm comm, MPI_Request *request) {
  return multimpi_MPI_Rsend_init(buf, count, datatype, dest, tag, comm,
                                 request);
}

int multimpi_MPI_Win_unlock_all(MPI_Win win);
static inline int MPI_Win_unlock_all(MPI_Win win) {
  return multimpi_MPI_Win_unlock_all(win);
}

int multimpi_MPI_File_sync(MPI_File fh);
static inline int MPI_File_sync(MPI_File fh) {
  return multimpi_MPI_File_sync(fh);
}

int multimpi_MPI_Scan(const void *sendbuf, void *recvbuf, int count,
                      MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
static inline int MPI_Scan(const void *sendbuf, void *recvbuf, int count,
                           MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return multimpi_MPI_Scan(sendbuf, recvbuf, count, datatype, op, comm);
}

int multimpi_MPI_Win_wait(MPI_Win win);
static inline int MPI_Win_wait(MPI_Win win) {
  return multimpi_MPI_Win_wait(win);
}

int multimpi_MPI_File_write(MPI_File fh, void *buf, int count,
                            MPI_Datatype datatype, MPI_Status *status);
static inline int MPI_File_write(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status) {
  return multimpi_MPI_File_write(fh, buf, count, datatype, status);
}

int multimpi_MPI_Scatter(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, void *recvbuf, int recvcount,
                         MPI_Datatype recvtype, int root, MPI_Comm comm);
static inline int MPI_Scatter(const void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              int recvcount, MPI_Datatype recvtype, int root,
                              MPI_Comm comm) {
  return multimpi_MPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                              recvtype, root, comm);
}

double multimpi_MPI_Wtick();
static inline double MPI_Wtick() { return multimpi_MPI_Wtick(); }

double multimpi_MPI_Wtime();
static inline double MPI_Wtime() { return multimpi_MPI_Wtime(); }

#ifdef __cplusplus
}
#endif
