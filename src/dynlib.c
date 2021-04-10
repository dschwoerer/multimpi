#include "mpi.h"
#include <stdio.h>

_Static_assert(sizeof(void *) >= sizeof(MPI_Comm), "Naive mapping for MPI_Comm not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Datatype), "Naive mapping for MPI_Datatype not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Op), "Naive mapping for MPI_Op not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Request), "Naive mapping for MPI_Request not working!");
_Static_assert(sizeof(struct {long a,b,c; }) >= sizeof(MPI_Status), "Naive mapping for MPI_Status not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Group), "Naive mapping for MPI_Group not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_File), "Naive mapping for MPI_File not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Win), "Naive mapping for MPI_Win not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Aint), "Naive mapping for MPI_Aint not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Offset), "Naive mapping for MPI_Offset not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Info), "Naive mapping for MPI_Info not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Errhandler), "Naive mapping for MPI_Errhandler not working!");
_Static_assert(sizeof(void *) >= sizeof(MPIO_Request), "Naive mapping for MPIO_Request not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Message), "Naive mapping for MPI_Message not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Delete_function), "Naive mapping for MPI_Delete_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_User_function), "Naive mapping for MPI_User_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Comm_copy_attr_function), "Naive mapping for MPI_Comm_copy_attr_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Comm_delete_attr_function), "Naive mapping for MPI_Comm_delete_attr_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Comm_errhandler_function), "Naive mapping for MPI_Comm_errhandler_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Copy_function), "Naive mapping for MPI_Copy_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Count), "Naive mapping for MPI_Count not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Datarep_conversion_function), "Naive mapping for MPI_Datarep_conversion_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Datarep_extent_function), "Naive mapping for MPI_Datarep_extent_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_File_errhandler_function), "Naive mapping for MPI_File_errhandler_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Fint), "Naive mapping for MPI_Fint not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Grequest_cancel_function), "Naive mapping for MPI_Grequest_cancel_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Grequest_free_function), "Naive mapping for MPI_Grequest_free_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Grequest_query_function), "Naive mapping for MPI_Grequest_query_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Handler_function), "Naive mapping for MPI_Handler_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_T_cvar_handle), "Naive mapping for MPI_T_cvar_handle not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_T_enum), "Naive mapping for MPI_T_enum not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_T_pvar_handle), "Naive mapping for MPI_T_pvar_handle not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_T_pvar_session), "Naive mapping for MPI_T_pvar_session not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Type_copy_attr_function), "Naive mapping for MPI_Type_copy_attr_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Type_delete_attr_function), "Naive mapping for MPI_Type_delete_attr_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Win_copy_attr_function), "Naive mapping for MPI_Win_copy_attr_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Win_delete_attr_function), "Naive mapping for MPI_Win_delete_attr_function not working!");
_Static_assert(sizeof(void *) >= sizeof(MPI_Win_errhandler_function), "Naive mapping for MPI_Win_errhandler_function not working!");
void * mpi_COMM_WORLD = MPI_COMM_WORLD;
void * mpi_COMM_NULL = MPI_COMM_NULL;
void * mpi_DOUBLE = MPI_DOUBLE;
void * mpi_INT = MPI_INT;
void * mpi_BYTE = MPI_BYTE;
void * mpi_CHAR = MPI_CHAR;
void * mpi_C_BOOL = MPI_C_BOOL;
void * mpi_DOUBLE_COMPLEX = MPI_DOUBLE_COMPLEX;
void * mpi_MAX = MPI_MAX;
void * mpi_MIN = MPI_MIN;
void * mpi_SUM = MPI_SUM;
void * mpi_LOR = MPI_LOR;
void * mpi_BOR = MPI_BOR;
void * mpi_LAND = MPI_LAND;
void * mpi_REQUEST_NULL = MPI_REQUEST_NULL;
void * mpi_GROUP_EMPTY = MPI_GROUP_EMPTY;
int mpi_SUCCESS = MPI_SUCCESS;
int mpi_UNDEFINED = MPI_UNDEFINED;
MPI_Status * mpi_STATUS_IGNORE = MPI_STATUS_IGNORE;
void multimpi_init(){

  if (sizeof(MPI_Comm) != sizeof(void *)){
    char * t = & mpi_COMM_WORLD;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_COMM_WORLD = MPI_COMM_WORLD;
  }


  if (sizeof(MPI_Comm) != sizeof(void *)){
    char * t = & mpi_COMM_NULL;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_COMM_NULL = MPI_COMM_NULL;
  }


  if (sizeof(MPI_Datatype) != sizeof(void *)){
    char * t = & mpi_DOUBLE;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_DOUBLE = MPI_DOUBLE;
  }


  if (sizeof(MPI_Datatype) != sizeof(void *)){
    char * t = & mpi_INT;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_INT = MPI_INT;
  }


  if (sizeof(MPI_Datatype) != sizeof(void *)){
    char * t = & mpi_BYTE;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_BYTE = MPI_BYTE;
  }


  if (sizeof(MPI_Datatype) != sizeof(void *)){
    char * t = & mpi_CHAR;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_CHAR = MPI_CHAR;
  }


  if (sizeof(MPI_Datatype) != sizeof(void *)){
    char * t = & mpi_C_BOOL;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_C_BOOL = MPI_C_BOOL;
  }


  if (sizeof(MPI_Datatype) != sizeof(void *)){
    char * t = & mpi_DOUBLE_COMPLEX;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_DOUBLE_COMPLEX = MPI_DOUBLE_COMPLEX;
  }


  if (sizeof(MPI_Op) != sizeof(void *)){
    char * t = & mpi_MAX;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_MAX = MPI_MAX;
  }


  if (sizeof(MPI_Op) != sizeof(void *)){
    char * t = & mpi_MIN;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_MIN = MPI_MIN;
  }


  if (sizeof(MPI_Op) != sizeof(void *)){
    char * t = & mpi_SUM;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_SUM = MPI_SUM;
  }


  if (sizeof(MPI_Op) != sizeof(void *)){
    char * t = & mpi_LOR;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_LOR = MPI_LOR;
  }


  if (sizeof(MPI_Op) != sizeof(void *)){
    char * t = & mpi_BOR;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_BOR = MPI_BOR;
  }


  if (sizeof(MPI_Op) != sizeof(void *)){
    char * t = & mpi_LAND;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_LAND = MPI_LAND;
  }


  if (sizeof(MPI_Request) != sizeof(void *)){
    char * t = & mpi_REQUEST_NULL;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_REQUEST_NULL = MPI_REQUEST_NULL;
  }


  if (sizeof(MPI_Group) != sizeof(void *)){
    char * t = & mpi_GROUP_EMPTY;
    for (int i=0; i< sizeof(void *) ; ++i) {
      t[i] = 0;
    }
    mpi_GROUP_EMPTY = MPI_GROUP_EMPTY;
  }

}

int mpi_File_write_all(void *fh, void *buf, int count, void *datatype, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPI_Status * status_ = status;
  int  ret = MPI_File_write_all(fh_, buf, count, datatype_, status_);
  fh = fh_;
  datatype = datatype_;
  status = status_;
  return ret; }

int mpi_Scatterv(const void *sendbuf, const int *sendcounts, const int *displs, void *sendtype, void *recvbuf, int recvcount, void *recvtype, int root, void *comm) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Scatterv(sendbuf, sendcounts, displs, sendtype_, recvbuf, recvcount, recvtype_, root, comm_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  return ret; }

int mpi_File_write_all_begin(void *fh, void *buf, int count, void *datatype) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_File_write_all_begin(fh_, buf, count, datatype_);
  fh = fh_;
  datatype = datatype_;
  return ret; }

int mpi_Send(const void *buf, int count, void *datatype, int dest, int tag, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Send(buf, count, datatype_, dest, tag, comm_);
  datatype = datatype_;
  comm = comm_;
  return ret; }

int mpi_File_write_all_end(void *fh, void *buf, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Status * status_ = status;
  int  ret = MPI_File_write_all_end(fh_, buf, status_);
  fh = fh_;
  status = status_;
  return ret; }

int mpi_Send_init(const void *buf, int count, void *datatype, int dest, int tag, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Send_init(buf, count, datatype_, dest, tag, comm_, request_);
  datatype = datatype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Abort(void *comm, int errorcode) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Abort(comm_, errorcode);
  comm = comm_;
  return ret; }

int mpi_File_write_at(void *fh, void *offset, void *buf, int count, void *datatype, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Offset offset_ = offset;
  MPI_Datatype datatype_ = datatype;
  MPI_Status * status_ = status;
  int  ret = MPI_File_write_at(fh_, offset_, buf, count, datatype_, status_);
  fh = fh_;
  offset = offset_;
  datatype = datatype_;
  status = status_;
  return ret; }

int mpi_Sendrecv(const void *sendbuf, int sendcount, void *sendtype, int dest, int sendtag, void *recvbuf, int recvcount, void *recvtype, int source, int recvtag, void *comm, struct {long a,b,c; }*status) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Status * status_ = status;
  int  ret = MPI_Sendrecv(sendbuf, sendcount, sendtype_, dest, sendtag, recvbuf, recvcount, recvtype_, source, recvtag, comm_, status_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  status = status_;
  return ret; }

int mpi_Accumulate(const void *origin_addr, int origin_count, MPI_Datatype
                   origin_datatype, int target_rank, MPI_Aint
                   target_disp, int target_count, MPI_Datatype
                   target_datatype, void *op, void *win) {
  MPI_Datatype origin_datatype_ = origin_datatype;
  MPI_Aint target_disp_ = target_disp;
  MPI_Datatype target_datatype_ = target_datatype;
  MPI_Op op_ = op;
  MPI_Win win_ = win;
  int  ret = MPI_Accumulate(origin_addr, origin_count, origin_datatype_, target_rank, target_disp_, target_count, target_datatype_, op_, win_);
  origin_datatype = origin_datatype_;
  target_disp = target_disp_;
  target_datatype = target_datatype_;
  op = op_;
  win = win_;
  return ret; }

int mpi_File_write_at_all(void *fh, void *offset, void *buf, int count, void *datatype, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Offset offset_ = offset;
  MPI_Datatype datatype_ = datatype;
  MPI_Status * status_ = status;
  int  ret = MPI_File_write_at_all(fh_, offset_, buf, count, datatype_, status_);
  fh = fh_;
  offset = offset_;
  datatype = datatype_;
  status = status_;
  return ret; }

int mpi_Sendrecv_replace(void *buf, int count, void *datatype, int dest, int sendtag, int source, int recvtag, void *comm, struct {long a,b,c; }*status) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Status * status_ = status;
  int  ret = MPI_Sendrecv_replace(buf, count, datatype_, dest, sendtag, source, recvtag, comm_, status_);
  datatype = datatype_;
  comm = comm_;
  status = status_;
  return ret; }

int mpi_Add_error_class(int *errorclass) {
  int  ret = MPI_Add_error_class(errorclass);
  return ret; }

int mpi_File_write_at_all_begin(void *fh, void *offset, void *buf, int count, void *datatype) {
  MPI_File fh_ = fh;
  MPI_Offset offset_ = offset;
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_File_write_at_all_begin(fh_, offset_, buf, count, datatype_);
  fh = fh_;
  offset = offset_;
  datatype = datatype_;
  return ret; }

int mpi_Ssend(const void *buf, int count, void *datatype, int dest, int tag, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Ssend(buf, count, datatype_, dest, tag, comm_);
  datatype = datatype_;
  comm = comm_;
  return ret; }

int mpi_Add_error_code(int errorclass, int *errorcode) {
  int  ret = MPI_Add_error_code(errorclass, errorcode);
  return ret; }

int mpi_File_write_at_all_end(void *fh, void *buf, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Status * status_ = status;
  int  ret = MPI_File_write_at_all_end(fh_, buf, status_);
  fh = fh_;
  status = status_;
  return ret; }

int mpi_Ssend_init(const void *buf, int count, void *datatype, int dest, int tag, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ssend_init(buf, count, datatype_, dest, tag, comm_, request_);
  datatype = datatype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Add_error_string(int errorcode, const char *string) {
  int  ret = MPI_Add_error_string(errorcode, string);
  return ret; }

int mpi_File_write_ordered(void *fh, void *buf, int count, void *datatype, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPI_Status * status_ = status;
  int  ret = MPI_File_write_ordered(fh_, buf, count, datatype_, status_);
  fh = fh_;
  datatype = datatype_;
  status = status_;
  return ret; }

int mpi_Start(void **request) {
  MPI_Request * request_ = request;
  int  ret = MPI_Start(request_);
  request = request_;
  return ret; }

int mpi_Address(const void *location, void **address) {
  MPI_Aint * address_ = address;
  int  ret = MPI_Address(location, address_);
  address = address_;
  return ret; }

int mpi_File_write_ordered_begin(void *fh, void *buf, int count, void *datatype) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_File_write_ordered_begin(fh_, buf, count, datatype_);
  fh = fh_;
  datatype = datatype_;
  return ret; }

int mpi_Startall(int count, void *array_of_requests[]) {
  MPI_Request array_of_requests_[count];
  for (int i=0;i<count;++i){
    array_of_requests_[i] = array_of_requests[i];
  }
  int  ret = MPI_Startall(count, array_of_requests_);
  for (int i=0;i<count;++i){
    array_of_requests_[i] = array_of_requests[i];
  }
  return ret; }

int mpi_Allgather(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, int recvcount, void *recvtype, void *comm) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Allgather(sendbuf, sendcount, sendtype_, recvbuf, recvcount, recvtype_, comm_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  return ret; }

int mpi_File_write_ordered_end(void *fh, void *buf, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Status * status_ = status;
  int  ret = MPI_File_write_ordered_end(fh_, buf, status_);
  fh = fh_;
  status = status_;
  return ret; }

int mpi_Status_set_cancelled(struct {long a,b,c; }*status, int flag) {
  MPI_Status * status_ = status;
  int  ret = MPI_Status_set_cancelled(status_, flag);
  status = status_;
  return ret; }

int mpi_Allgatherv(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, const int *recvcounts, const int *displs, void *recvtype, void *comm) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Allgatherv(sendbuf, sendcount, sendtype_, recvbuf, recvcounts, displs, recvtype_, comm_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  return ret; }

int mpi_File_write_shared(void *fh, void *buf, int count, void *datatype, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPI_Status * status_ = status;
  int  ret = MPI_File_write_shared(fh_, buf, count, datatype_, status_);
  fh = fh_;
  datatype = datatype_;
  status = status_;
  return ret; }

int mpi_Status_set_elements(struct {long a,b,c; }*status, void *datatype, int count) {
  MPI_Status * status_ = status;
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_Status_set_elements(status_, datatype_, count);
  status = status_;
  datatype = datatype_;
  return ret; }

int mpi_Alloc_mem(void *size, void *info, void *baseptr) {
  MPI_Aint size_ = size;
  MPI_Info info_ = info;
  int  ret = MPI_Alloc_mem(size_, info_, baseptr);
  size = size_;
  info = info_;
  return ret; }

int mpi_Finalize() {
  int  ret = MPI_Finalize();
  return ret; }

int mpi_Status_set_elements_x(struct {long a,b,c; }*status, void *datatype, void *count) {
  MPI_Status * status_ = status;
  MPI_Datatype datatype_ = datatype;
  MPI_Count count_ = count;
  int  ret = MPI_Status_set_elements_x(status_, datatype_, count_);
  status = status_;
  datatype = datatype_;
  count = count_;
  return ret; }

int mpi_Allreduce(const void *sendbuf, void *recvbuf, int count, void *datatype, void *op, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Allreduce(sendbuf, recvbuf, count, datatype_, op_, comm_);
  datatype = datatype_;
  op = op_;
  comm = comm_;
  return ret; }

int mpi_Finalized(int *flag) {
  int  ret = MPI_Finalized(flag);
  return ret; }

int mpi_T_category_changed(int *stamp) {
  int  ret = MPI_T_category_changed(stamp);
  return ret; }

int mpi_Alltoall(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, int recvcount, void *recvtype, void *comm) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Alltoall(sendbuf, sendcount, sendtype_, recvbuf, recvcount, recvtype_, comm_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  return ret; }

int mpi_Free_mem(void *base) {
  int  ret = MPI_Free_mem(base);
  return ret; }

int mpi_T_category_get_categories(int cat_index, int len, int indices[]) {
  int  ret = MPI_T_category_get_categories(cat_index, len, indices);
  return ret; }

int mpi_Alltoallv(const void *sendbuf, const int *sendcounts, const int *sdispls, void *sendtype, void *recvbuf, const int *recvcounts, const int *rdispls, void *recvtype, void *comm) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype_, recvbuf, recvcounts, rdispls, recvtype_, comm_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  return ret; }

int mpi_Gather(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, int recvcount, void *recvtype, int root, void *comm) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Gather(sendbuf, sendcount, sendtype_, recvbuf, recvcount, recvtype_, root, comm_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  return ret; }

int mpi_T_category_get_cvars(int cat_index, int len, int indices[]) {
  int  ret = MPI_T_category_get_cvars(cat_index, len, indices);
  return ret; }

int mpi_Alltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const void *sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const void *recvtypes[], void *comm) {
fprintf(stderr, "MPI_Alltoallw is not implementented in MultiMPI - use MPI directly\n");
MPI_Abort(MPI_COMM_WORLD, 1);
fprintf(stderr, "MPI_Alltoallw is not implementented in MultiMPI - use MPI directly\n");
MPI_Abort(MPI_COMM_WORLD, 1);
  MPI_Comm comm_ = comm;
  int  ret = MPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_);
  comm = comm_;
  return ret; }

int mpi_Gatherv(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, const int *recvcounts, const int *displs, void *recvtype, int root, void *comm) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Gatherv(sendbuf, sendcount, sendtype_, recvbuf, recvcounts, displs, recvtype_, root, comm_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  return ret; }

int mpi_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len, int *num_cvars, int *num_pvars, int *num_categories) {
  int  ret = MPI_T_category_get_info(cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories);
  return ret; }

int mpi_Attr_delete(void *comm, int keyval) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Attr_delete(comm_, keyval);
  comm = comm_;
  return ret; }

int mpi_Get(void *origin_addr, int origin_count, MPI_Datatype
            origin_datatype, int target_rank, void *target_disp, int target_count, void *target_datatype, MPI_Win
            win) {
  MPI_Datatype origin_datatype_ = origin_datatype;
  MPI_Aint target_disp_ = target_disp;
  MPI_Datatype target_datatype_ = target_datatype;
  MPI_Win win_ = win;
  int  ret = MPI_Get(origin_addr, origin_count, origin_datatype_, target_rank, target_disp_, target_count, target_datatype_, win_);
  origin_datatype = origin_datatype_;
  target_disp = target_disp_;
  target_datatype = target_datatype_;
  win = win_;
  return ret; }

int mpi_T_category_get_num(int *num_cat) {
  int  ret = MPI_T_category_get_num(num_cat);
  return ret; }

int mpi_Attr_get(void *comm, int keyval, void *attribute_val, int *flag) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Attr_get(comm_, keyval, attribute_val, flag);
  comm = comm_;
  return ret; }

int mpi_Get_accumulate(const void *origin_addr, int origin_count, void *origin_datatype, void *result_addr, int result_count, void *result_datatype, int target_rank, void *target_disp, int target_count, void *target_datatype, void *op, void *win) {
  MPI_Datatype origin_datatype_ = origin_datatype;
  MPI_Datatype result_datatype_ = result_datatype;
  MPI_Aint target_disp_ = target_disp;
  MPI_Datatype target_datatype_ = target_datatype;
  MPI_Op op_ = op;
  MPI_Win win_ = win;
  int  ret = MPI_Get_accumulate(origin_addr, origin_count, origin_datatype_, result_addr, result_count, result_datatype_, target_rank, target_disp_, target_count, target_datatype_, op_, win_);
  origin_datatype = origin_datatype_;
  result_datatype = result_datatype_;
  target_disp = target_disp_;
  target_datatype = target_datatype_;
  op = op_;
  win = win_;
  return ret; }

int mpi_T_category_get_pvars(int cat_index, int len, int indices[]) {
  int  ret = MPI_T_category_get_pvars(cat_index, len, indices);
  return ret; }

int mpi_Attr_put(void *comm, int keyval, void *attribute_val) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Attr_put(comm_, keyval, attribute_val);
  comm = comm_;
  return ret; }

int mpi_Get_address(const void *location, void **address) {
  MPI_Aint * address_ = address;
  int  ret = MPI_Get_address(location, address_);
  address = address_;
  return ret; }

int mpi_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity, void **datatype, void **enumtype, char *desc, int *desc_len, int *binding, int *scope) {
  MPI_Datatype * datatype_ = datatype;
  MPI_T_enum * enumtype_ = enumtype;
  int  ret = MPI_T_cvar_get_info(cvar_index, name, name_len, verbosity, datatype_, enumtype_, desc, desc_len, binding, scope);
  datatype = datatype_;
  enumtype = enumtype_;
  return ret; }

int mpi_Barrier(void *comm) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Barrier(comm_);
  comm = comm_;
  return ret; }

int mpi_Get_count(const struct {long a,b,c; }*status, void *datatype, int *count) {
  const MPI_Status * status_ = status;
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_Get_count(status_, datatype_, count);
  status = status_;
  datatype = datatype_;
  return ret; }

int mpi_T_cvar_get_num(int *num_cvar) {
  int  ret = MPI_T_cvar_get_num(num_cvar);
  return ret; }

int mpi_Bcast(void *buffer, int count, void *datatype, int root, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Bcast(buffer, count, datatype_, root, comm_);
  datatype = datatype_;
  comm = comm_;
  return ret; }

int mpi_Get_elements(const struct {long a,b,c; }*status, void *datatype, int *count) {
  const MPI_Status * status_ = status;
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_Get_elements(status_, datatype_, count);
  status = status_;
  datatype = datatype_;
  return ret; }

int mpi_T_cvar_handle_alloc(int cvar_index, void *obj_handle, void **handle, int *count) {
  MPI_T_cvar_handle * handle_ = handle;
  int  ret = MPI_T_cvar_handle_alloc(cvar_index, obj_handle, handle_, count);
  handle = handle_;
  return ret; }

int mpi_Bsend(const void *buf, int count, void *datatype, int dest, int tag, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Bsend(buf, count, datatype_, dest, tag, comm_);
  datatype = datatype_;
  comm = comm_;
  return ret; }

int mpi_Get_elements_x(const struct {long a,b,c; }*status, void *datatype, void **count) {
  const MPI_Status * status_ = status;
  MPI_Datatype datatype_ = datatype;
  MPI_Count * count_ = count;
  int  ret = MPI_Get_elements_x(status_, datatype_, count_);
  status = status_;
  datatype = datatype_;
  count = count_;
  return ret; }

int mpi_T_cvar_handle_free(void **handle) {
  MPI_T_cvar_handle * handle_ = handle;
  int  ret = MPI_T_cvar_handle_free(handle_);
  handle = handle_;
  return ret; }

int mpi_Bsend_init(const void *buf, int count, void *datatype, int dest, int tag, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Bsend_init(buf, count, datatype_, dest, tag, comm_, request_);
  datatype = datatype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Get_library_version(char *version, int *resultlen) {
  int  ret = MPI_Get_library_version(version, resultlen);
  return ret; }

int mpi_T_cvar_read(void *handle, void *buf) {
  MPI_T_cvar_handle handle_ = handle;
  int  ret = MPI_T_cvar_read(handle_, buf);
  handle = handle_;
  return ret; }

int mpi_Buffer_attach(void *buffer, int size) {
  int  ret = MPI_Buffer_attach(buffer, size);
  return ret; }

int mpi_Get_processor_name(char *name, int *resultlen) {
  int  ret = MPI_Get_processor_name(name, resultlen);
  return ret; }

int mpi_T_cvar_write(void *handle, void *buf) {
  MPI_T_cvar_handle handle_ = handle;
  int  ret = MPI_T_cvar_write(handle_, buf);
  handle = handle_;
  return ret; }

int mpi_Buffer_detach(void *buffer_addr, int *size) {
  int  ret = MPI_Buffer_detach(buffer_addr, size);
  return ret; }

int mpi_Get_version(int *version, int *subversion) {
  int  ret = MPI_Get_version(version, subversion);
  return ret; }

int mpi_T_enum_get_info(void *enumtype, int *num, char *name, int *name_len) {
  MPI_T_enum enumtype_ = enumtype;
  int  ret = MPI_T_enum_get_info(enumtype_, num, name, name_len);
  enumtype = enumtype_;
  return ret; }

int mpi_Cancel(void **request) {
  MPI_Request * request_ = request;
  int  ret = MPI_Cancel(request_);
  request = request_;
  return ret; }

int mpi_Graph_create(void *comm_old, int nnodes, const int indx[], const int edges[], int reorder, void **comm_graph) {
  MPI_Comm comm_old_ = comm_old;
  MPI_Comm * comm_graph_ = comm_graph;
  int  ret = MPI_Graph_create(comm_old_, nnodes, indx, edges, reorder, comm_graph_);
  comm_old = comm_old_;
  comm_graph = comm_graph_;
  return ret; }

int mpi_T_enum_get_item(void *enumtype, int index, int *value, char *name, int *name_len) {
  MPI_T_enum enumtype_ = enumtype;
  int  ret = MPI_T_enum_get_item(enumtype_, index, value, name, name_len);
  enumtype = enumtype_;
  return ret; }

int mpi_Cart_coords(void *comm, int rank, int maxdims, int coords[]) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Cart_coords(comm_, rank, maxdims, coords);
  comm = comm_;
  return ret; }

int mpi_Graph_get(void *comm, int maxindex, int maxedges, int indx[], int edges[]) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Graph_get(comm_, maxindex, maxedges, indx, edges);
  comm = comm_;
  return ret; }

int mpi_T_finalize() {
  int  ret = MPI_T_finalize();
  return ret; }

int mpi_Cart_create(void *comm_old, int ndims, const int dims[], const int periods[], int reorder, void **comm_cart) {
  MPI_Comm comm_old_ = comm_old;
  MPI_Comm * comm_cart_ = comm_cart;
  int  ret = MPI_Cart_create(comm_old_, ndims, dims, periods, reorder, comm_cart_);
  comm_old = comm_old_;
  comm_cart = comm_cart_;
  return ret; }

int mpi_Graph_map(void *comm, int nnodes, const int indx[], const int edges[], int *newrank) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Graph_map(comm_, nnodes, indx, edges, newrank);
  comm = comm_;
  return ret; }

int mpi_T_init_thread(int required, int *provided) {
  int  ret = MPI_T_init_thread(required, provided);
  return ret; }

int mpi_Cart_get(void *comm, int maxdims, int dims[], int periods[], int coords[]) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Cart_get(comm_, maxdims, dims, periods, coords);
  comm = comm_;
  return ret; }

int mpi_Graph_neighbors(void *comm, int rank, int maxneighbors, int neighbors[]) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Graph_neighbors(comm_, rank, maxneighbors, neighbors);
  comm = comm_;
  return ret; }

int mpi_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class, void **datatype, void **enumtype, char *desc, int *desc_len, int *binding, int *readonly, int *continuous, int *atomic) {
  MPI_Datatype * datatype_ = datatype;
  MPI_T_enum * enumtype_ = enumtype;
  int  ret = MPI_T_pvar_get_info(pvar_index, name, name_len, verbosity, var_class, datatype_, enumtype_, desc, desc_len, binding, readonly, continuous, atomic);
  datatype = datatype_;
  enumtype = enumtype_;
  return ret; }

int mpi_Cart_map(void *comm, int ndims, const int dims[], const int periods[], int *newrank) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Cart_map(comm_, ndims, dims, periods, newrank);
  comm = comm_;
  return ret; }

int mpi_Graph_neighbors_count(void *comm, int rank, int *nneighbors) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Graph_neighbors_count(comm_, rank, nneighbors);
  comm = comm_;
  return ret; }

int mpi_T_pvar_get_num(int *num_pvar) {
  int  ret = MPI_T_pvar_get_num(num_pvar);
  return ret; }

int mpi_Cart_rank(void *comm, const int coords[], int *rank) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Cart_rank(comm_, coords, rank);
  comm = comm_;
  return ret; }

int mpi_Graphdims_get(void *comm, int *nnodes, int *nedges) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Graphdims_get(comm_, nnodes, nedges);
  comm = comm_;
  return ret; }

int mpi_T_pvar_handle_alloc(void *session, int pvar_index, void *obj_handle, void **handle, int *count) {
  MPI_T_pvar_session session_ = session;
  MPI_T_pvar_handle * handle_ = handle;
  int  ret = MPI_T_pvar_handle_alloc(session_, pvar_index, obj_handle, handle_, count);
  session = session_;
  handle = handle_;
  return ret; }

int mpi_Cart_shift(void *comm, int direction, int disp, int *rank_source, int *rank_dest) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Cart_shift(comm_, direction, disp, rank_source, rank_dest);
  comm = comm_;
  return ret; }

int mpi_Grequest_complete(void *request) {
  MPI_Request request_ = request;
  int  ret = MPI_Grequest_complete(request_);
  request = request_;
  return ret; }

int mpi_T_pvar_handle_free(void *session, void **handle) {
  MPI_T_pvar_session session_ = session;
  MPI_T_pvar_handle * handle_ = handle;
  int  ret = MPI_T_pvar_handle_free(session_, handle_);
  session = session_;
  handle = handle_;
  return ret; }

int mpi_Cart_sub(void *comm, const int remain_dims[], void **newcomm) {
  MPI_Comm comm_ = comm;
  MPI_Comm * newcomm_ = newcomm;
  int  ret = MPI_Cart_sub(comm_, remain_dims, newcomm_);
  comm = comm_;
  newcomm = newcomm_;
  return ret; }

int mpi_Grequest_start(void **query_fn, void **free_fn, void **cancel_fn, void *extra_state, void **request) {
  MPI_Grequest_query_function * query_fn_ = query_fn;
  MPI_Grequest_free_function * free_fn_ = free_fn;
  MPI_Grequest_cancel_function * cancel_fn_ = cancel_fn;
  MPI_Request * request_ = request;
  int  ret = MPI_Grequest_start(query_fn_, free_fn_, cancel_fn_, extra_state, request_);
  query_fn = query_fn_;
  free_fn = free_fn_;
  cancel_fn = cancel_fn_;
  request = request_;
  return ret; }

int mpi_T_pvar_read(void *session, void *handle, void *buf) {
  MPI_T_pvar_session session_ = session;
  MPI_T_pvar_handle handle_ = handle;
  int  ret = MPI_T_pvar_read(session_, handle_, buf);
  session = session_;
  handle = handle_;
  return ret; }

int mpi_Cartdim_get(void *comm, int *ndims) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Cartdim_get(comm_, ndims);
  comm = comm_;
  return ret; }

int mpi_Group_compare(void *group1, void *group2, int *result) {
  MPI_Group group1_ = group1;
  MPI_Group group2_ = group2;
  int  ret = MPI_Group_compare(group1_, group2_, result);
  group1 = group1_;
  group2 = group2_;
  return ret; }

int mpi_T_pvar_readreset(void *session, void *handle, void *buf) {
  MPI_T_pvar_session session_ = session;
  MPI_T_pvar_handle handle_ = handle;
  int  ret = MPI_T_pvar_readreset(session_, handle_, buf);
  session = session_;
  handle = handle_;
  return ret; }

int mpi_Close_port(const char *port_name) {
  int  ret = MPI_Close_port(port_name);
  return ret; }

int mpi_Group_difference(void *group1, void *group2, void **newgroup) {
  MPI_Group group1_ = group1;
  MPI_Group group2_ = group2;
  MPI_Group * newgroup_ = newgroup;
  int  ret = MPI_Group_difference(group1_, group2_, newgroup_);
  group1 = group1_;
  group2 = group2_;
  newgroup = newgroup_;
  return ret; }

int mpi_T_pvar_reset(void *session, void *handle) {
  MPI_T_pvar_session session_ = session;
  MPI_T_pvar_handle handle_ = handle;
  int  ret = MPI_T_pvar_reset(session_, handle_);
  session = session_;
  handle = handle_;
  return ret; }

int mpi_Comm_accept(const char *port_name, void *info, int root, void *comm, void **newcomm) {
  MPI_Info info_ = info;
  MPI_Comm comm_ = comm;
  MPI_Comm * newcomm_ = newcomm;
  int  ret = MPI_Comm_accept(port_name, info_, root, comm_, newcomm_);
  info = info_;
  comm = comm_;
  newcomm = newcomm_;
  return ret; }

int mpi_Group_excl(void *group, int n, const int ranks[], void **newgroup) {
  MPI_Group group_ = group;
  MPI_Group * newgroup_ = newgroup;
  int  ret = MPI_Group_excl(group_, n, ranks, newgroup_);
  group = group_;
  newgroup = newgroup_;
  return ret; }

int mpi_T_pvar_session_create(void **session) {
  MPI_T_pvar_session * session_ = session;
  int  ret = MPI_T_pvar_session_create(session_);
  session = session_;
  return ret; }

int mpi_Comm_call_errhandler(void *comm, int errorcode) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Comm_call_errhandler(comm_, errorcode);
  comm = comm_;
  return ret; }

int mpi_Group_free(void **group) {
  MPI_Group * group_ = group;
  int  ret = MPI_Group_free(group_);
  group = group_;
  return ret; }

int mpi_T_pvar_session_free(void **session) {
  MPI_T_pvar_session * session_ = session;
  int  ret = MPI_T_pvar_session_free(session_);
  session = session_;
  return ret; }

int mpi_Comm_compare(void *comm1, void *comm2, int *result) {
  MPI_Comm comm1_ = comm1;
  MPI_Comm comm2_ = comm2;
  int  ret = MPI_Comm_compare(comm1_, comm2_, result);
  comm1 = comm1_;
  comm2 = comm2_;
  return ret; }

int mpi_Group_incl(void *group, int n, const int ranks[], void **newgroup) {
  MPI_Group group_ = group;
  MPI_Group * newgroup_ = newgroup;
  int  ret = MPI_Group_incl(group_, n, ranks, newgroup_);
  group = group_;
  newgroup = newgroup_;
  return ret; }

int mpi_T_pvar_start(void *session, void *handle) {
  MPI_T_pvar_session session_ = session;
  MPI_T_pvar_handle handle_ = handle;
  int  ret = MPI_T_pvar_start(session_, handle_);
  session = session_;
  handle = handle_;
  return ret; }

int mpi_Comm_connect(const char *port_name, void *info, int root, void *comm, void **newcomm) {
  MPI_Info info_ = info;
  MPI_Comm comm_ = comm;
  MPI_Comm * newcomm_ = newcomm;
  int  ret = MPI_Comm_connect(port_name, info_, root, comm_, newcomm_);
  info = info_;
  comm = comm_;
  newcomm = newcomm_;
  return ret; }

int mpi_Group_intersection(void *group1, void *group2, void **newgroup) {
  MPI_Group group1_ = group1;
  MPI_Group group2_ = group2;
  MPI_Group * newgroup_ = newgroup;
  int  ret = MPI_Group_intersection(group1_, group2_, newgroup_);
  group1 = group1_;
  group2 = group2_;
  newgroup = newgroup_;
  return ret; }

int mpi_T_pvar_stop(void *session, void *handle) {
  MPI_T_pvar_session session_ = session;
  MPI_T_pvar_handle handle_ = handle;
  int  ret = MPI_T_pvar_stop(session_, handle_);
  session = session_;
  handle = handle_;
  return ret; }

int mpi_Comm_create(void *comm, void *group, void **newcomm) {
  MPI_Comm comm_ = comm;
  MPI_Group group_ = group;
  MPI_Comm * newcomm_ = newcomm;
  int  ret = MPI_Comm_create(comm_, group_, newcomm_);
  comm = comm_;
  group = group_;
  newcomm = newcomm_;
  return ret; }

int mpi_Group_range_excl(void *group, int n, int ranges[][3], void **newgroup) {
  MPI_Group group_ = group;
  MPI_Group * newgroup_ = newgroup;
  int  ret = MPI_Group_range_excl(group_, n, ranges, newgroup_);
  group = group_;
  newgroup = newgroup_;
  return ret; }

int mpi_T_pvar_write(void *session, void *handle, void *buf) {
  MPI_T_pvar_session session_ = session;
  MPI_T_pvar_handle handle_ = handle;
  int  ret = MPI_T_pvar_write(session_, handle_, buf);
  session = session_;
  handle = handle_;
  return ret; }

int mpi_Comm_create_errhandler(void **comm_errhandler_fn, void **errhandler) {
  MPI_Comm_errhandler_function * comm_errhandler_fn_ = comm_errhandler_fn;
  MPI_Errhandler * errhandler_ = errhandler;
  int  ret = MPI_Comm_create_errhandler(comm_errhandler_fn_, errhandler_);
  comm_errhandler_fn = comm_errhandler_fn_;
  errhandler = errhandler_;
  return ret; }

int mpi_Group_range_incl(void *group, int n, int ranges[][3], void **newgroup) {
  MPI_Group group_ = group;
  MPI_Group * newgroup_ = newgroup;
  int  ret = MPI_Group_range_incl(group_, n, ranges, newgroup_);
  group = group_;
  newgroup = newgroup_;
  return ret; }

int mpi_Test(void **request, int *flag, struct {long a,b,c; }*status) {
  MPI_Request * request_ = request;
  MPI_Status * status_ = status;
  int  ret = MPI_Test(request_, flag, status_);
  request = request_;
  status = status_;
  return ret; }

int mpi_Comm_create_group(void *comm, void *group, int tag, void ** newcomm) {
  MPI_Comm comm_ = comm;
  MPI_Group group_ = group;
  MPI_Comm * newcomm_ = newcomm;
  int  ret = MPI_Comm_create_group(comm_, group_, tag, newcomm_);
  comm = comm_;
  group = group_;
  newcomm = newcomm_;
  return ret; }

int mpi_Group_rank(void *group, int *rank) {
  MPI_Group group_ = group;
  int  ret = MPI_Group_rank(group_, rank);
  group = group_;
  return ret; }

int mpi_Test_cancelled(const struct {long a,b,c; }*status, int *flag) {
  const MPI_Status * status_ = status;
  int  ret = MPI_Test_cancelled(status_, flag);
  status = status_;
  return ret; }

int mpi_Comm_create_keyval(void **comm_copy_attr_fn, void **comm_delete_attr_fn, int *comm_keyval, void *extra_state) {
  MPI_Comm_copy_attr_function * comm_copy_attr_fn_ = comm_copy_attr_fn;
  MPI_Comm_delete_attr_function * comm_delete_attr_fn_ = comm_delete_attr_fn;
  int  ret = MPI_Comm_create_keyval(comm_copy_attr_fn_, comm_delete_attr_fn_, comm_keyval, extra_state);
  comm_copy_attr_fn = comm_copy_attr_fn_;
  comm_delete_attr_fn = comm_delete_attr_fn_;
  return ret; }

int mpi_Group_size(void *group, int *size) {
  MPI_Group group_ = group;
  int  ret = MPI_Group_size(group_, size);
  group = group_;
  return ret; }

int mpi_Testall(int count, void *array_of_requests[], int *flag, struct {long a,b,c; }array_of_statuses[]) {
  MPI_Request array_of_requests_[count];
  MPI_Status array_of_statuses_[count];
  for (int i=0;i<count;++i){
    array_of_requests_[i] = array_of_requests[i];

    char * a = array_of_statuses_ + i;
    char * b = array_of_statuses + i;
    int j=0;
    for (;j<sizeof(MPI_Status); ++j){
      a[j] = b[j];
    }

  }
  int  ret = MPI_Testall(count, array_of_requests_, flag, array_of_statuses_);
  for (int i=0;i<count;++i){
    array_of_requests_[i] = array_of_requests[i];

    char * a = array_of_statuses + i;
    char * b = array_of_statuses_ + i;
    int j=0;
    for (;j<sizeof(MPI_Status); ++j){
      a[j] = b[j];
    }


    for (;j<sizeof(struct {long a,b,c; }); ++j){
      a[j] = b[j];
    }
    
  }
  return ret; }

int mpi_Comm_delete_attr(void *comm, int comm_keyval) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Comm_delete_attr(comm_, comm_keyval);
  comm = comm_;
  return ret; }

int mpi_Group_translate_ranks(void *group1, int n, const int ranks1[], void *group2, int ranks2[]) {
  MPI_Group group1_ = group1;
  MPI_Group group2_ = group2;
  int  ret = MPI_Group_translate_ranks(group1_, n, ranks1, group2_, ranks2);
  group1 = group1_;
  group2 = group2_;
  return ret; }

int mpi_Testany(int count, void *array_of_requests[], int *indx, int *flag, struct {long a,b,c; }*status) {
  MPI_Request array_of_requests_[count];
  MPI_Status * status_ = status;
  for (int i=0;i<count;++i){
    array_of_requests_[i] = array_of_requests[i];
  }
  int  ret = MPI_Testany(count, array_of_requests_, indx, flag, status_);
  for (int i=0;i<count;++i){
    array_of_requests_[i] = array_of_requests[i];
  }
  status = status_;
  return ret; }

int mpi_Comm_disconnect(void ** comm) {
  MPI_Comm * comm_ = comm;
  int  ret = MPI_Comm_disconnect(comm_);
  comm = comm_;
  return ret; }

int mpi_Group_union(void *group1, void *group2, void **newgroup) {
  MPI_Group group1_ = group1;
  MPI_Group group2_ = group2;
  MPI_Group * newgroup_ = newgroup;
  int  ret = MPI_Group_union(group1_, group2_, newgroup_);
  group1 = group1_;
  group2 = group2_;
  newgroup = newgroup_;
  return ret; }

int mpi_Testsome(int incount, void *array_of_requests[], int *outcount, int array_of_indices[], struct {long a,b,c; }array_of_statuses[]) {
  MPI_Request array_of_requests_[incount];
  MPI_Status array_of_statuses_[*outcount];
  for (int i=0;i<incount;++i){
    array_of_requests_[i] = array_of_requests[i];
  }
  for (int i=0;i<*outcount;++i){

    char * a = array_of_statuses_ + i;
    char * b = array_of_statuses + i;
    int j=0;
    for (;j<sizeof(MPI_Status); ++j){
      a[j] = b[j];
    }

  }
  int  ret = MPI_Testsome(incount, array_of_requests_, outcount, array_of_indices, array_of_statuses_);
  for (int i=0;i<incount;++i){
    array_of_requests_[i] = array_of_requests[i];
  }
  for (int i=0;i<*outcount;++i){

    char * a = array_of_statuses + i;
    char * b = array_of_statuses_ + i;
    int j=0;
    for (;j<sizeof(MPI_Status); ++j){
      a[j] = b[j];
    }


    for (;j<sizeof(struct {long a,b,c; }); ++j){
      a[j] = b[j];
    }
    
  }
  return ret; }

int mpi_Comm_dup(void *comm, void **newcomm) {
  MPI_Comm comm_ = comm;
  MPI_Comm * newcomm_ = newcomm;
  int  ret = MPI_Comm_dup(comm_, newcomm_);
  comm = comm_;
  newcomm = newcomm_;
  return ret; }

int mpi_Iallgather(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, int recvcount, void *recvtype, void *comm, void **request) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Iallgather(sendbuf, sendcount, sendtype_, recvbuf, recvcount, recvtype_, comm_, request_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Topo_test(void *comm, int *status) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Topo_test(comm_, status);
  comm = comm_;
  return ret; }

int mpi_Comm_dup_with_info(void *comm, void *info, void ** newcomm) {
  MPI_Comm comm_ = comm;
  MPI_Info info_ = info;
  MPI_Comm * newcomm_ = newcomm;
  int  ret = MPI_Comm_dup_with_info(comm_, info_, newcomm_);
  comm = comm_;
  info = info_;
  newcomm = newcomm_;
  return ret; }

int mpi_Iallgatherv(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, const int recvcounts[], const int displs[], void *recvtype, void *comm, void **request) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Iallgatherv(sendbuf, sendcount, sendtype_, recvbuf, recvcounts, displs, recvtype_, comm_, request_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_commit(void **datatype) {
  MPI_Datatype * datatype_ = datatype;
  int  ret = MPI_Type_commit(datatype_);
  datatype = datatype_;
  return ret; }

int mpi_Comm_free(void **comm) {
  MPI_Comm * comm_ = comm;
  int  ret = MPI_Comm_free(comm_);
  comm = comm_;
  return ret; }

int mpi_Iallreduce(const void *sendbuf, void *recvbuf, int count, void *datatype, void *op, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Iallreduce(sendbuf, recvbuf, count, datatype_, op_, comm_, request_);
  datatype = datatype_;
  op = op_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_contiguous(int count, void *oldtype, void **newtype) {
  MPI_Datatype oldtype_ = oldtype;
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_contiguous(count, oldtype_, newtype_);
  oldtype = oldtype_;
  newtype = newtype_;
  return ret; }

int mpi_Comm_free_keyval(int *comm_keyval) {
  int  ret = MPI_Comm_free_keyval(comm_keyval);
  return ret; }

int mpi_Ialltoall(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, int recvcount, void *recvtype, void *comm, void **request) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ialltoall(sendbuf, sendcount, sendtype_, recvbuf, recvcount, recvtype_, comm_, request_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[], const int array_of_distribs[], const int array_of_dargs[], const int array_of_psizes[], int order, void *oldtype, void **newtype) {
  MPI_Datatype oldtype_ = oldtype;
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype_, newtype_);
  oldtype = oldtype_;
  newtype = newtype_;
  return ret; }

int mpi_Comm_get_attr(void *comm, int comm_keyval, void *attribute_val, int *flag) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Comm_get_attr(comm_, comm_keyval, attribute_val, flag);
  comm = comm_;
  return ret; }

int mpi_Ialltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], void *sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], void *recvtype, void *comm, void **request) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype_, recvbuf, recvcounts, rdispls, recvtype_, comm_, request_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_create_f90_complex(int precision, int range, void **newtype) {
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_create_f90_complex(precision, range, newtype_);
  newtype = newtype_;
  return ret; }

int mpi_Comm_get_errhandler(void *comm, void **errhandler) {
  MPI_Comm comm_ = comm;
  MPI_Errhandler * errhandler_ = errhandler;
  int  ret = MPI_Comm_get_errhandler(comm_, errhandler_);
  comm = comm_;
  errhandler = errhandler_;
  return ret; }

int mpi_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[], const void *sendtypes[], void *recvbuf, const int recvcounts[], const int rdispls[], const void *recvtypes[], void *comm, void **request) {
fprintf(stderr, "MPI_Ialltoallw is not implementented in MultiMPI - use MPI directly\n");
MPI_Abort(MPI_COMM_WORLD, 1);
fprintf(stderr, "MPI_Ialltoallw is not implementented in MultiMPI - use MPI directly\n");
MPI_Abort(MPI_COMM_WORLD, 1);
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_, request_);
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_create_f90_integer(int range, void **newtype) {
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_create_f90_integer(range, newtype_);
  newtype = newtype_;
  return ret; }

int mpi_Comm_get_info(void *comm, void ** info_used) {
  MPI_Comm comm_ = comm;
  MPI_Info * info_used_ = info_used;
  int  ret = MPI_Comm_get_info(comm_, info_used_);
  comm = comm_;
  info_used = info_used_;
  return ret; }

int mpi_Ibarrier(void *comm, void **request) {
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ibarrier(comm_, request_);
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_create_f90_real(int precision, int range, void **newtype) {
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_create_f90_real(precision, range, newtype_);
  newtype = newtype_;
  return ret; }

int mpi_Comm_get_name(void *comm, char *comm_name, int *resultlen) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Comm_get_name(comm_, comm_name, resultlen);
  comm = comm_;
  return ret; }

int mpi_Ibcast(void *buffer, int count, void *datatype, int root, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ibcast(buffer, count, datatype_, root, comm_, request_);
  datatype = datatype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_create_hindexed(int count, const int array_of_blocklengths[], const void *array_of_displacements[], void *oldtype, void **newtype) {
  MPI_Aint array_of_displacements_[count];
  MPI_Datatype oldtype_ = oldtype;
  MPI_Datatype * newtype_ = newtype;
  for (int i=0;i<count;++i){
    array_of_displacements_[i] = array_of_displacements[i];
  }
  int  ret = MPI_Type_create_hindexed(count, array_of_blocklengths, array_of_displacements_, oldtype_, newtype_);
  for (int i=0;i<count;++i){
    array_of_displacements_[i] = array_of_displacements[i];
  }
  oldtype = oldtype_;
  newtype = newtype_;
  return ret; }

int mpi_Comm_get_parent(void **parent) {
  MPI_Comm * parent_ = parent;
  int  ret = MPI_Comm_get_parent(parent_);
  parent = parent_;
  return ret; }

int mpi_Ibsend(const void *buf, int count, void *datatype, int dest, int tag, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ibsend(buf, count, datatype_, dest, tag, comm_, request_);
  datatype = datatype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_create_hindexed_block(int count, int blocklength, const void *array_of_displacements[], void *oldtype, void ** newtype) {
  MPI_Aint array_of_displacements_[count];
  MPI_Datatype oldtype_ = oldtype;
  MPI_Datatype * newtype_ = newtype;
  for (int i=0;i<count;++i){
    array_of_displacements_[i] = array_of_displacements[i];
  }
  int  ret = MPI_Type_create_hindexed_block(count, blocklength, array_of_displacements_, oldtype_, newtype_);
  for (int i=0;i<count;++i){
    array_of_displacements_[i] = array_of_displacements[i];
  }
  oldtype = oldtype_;
  newtype = newtype_;
  return ret; }

int mpi_Comm_group(void *comm, void **group) {
  MPI_Comm comm_ = comm;
  MPI_Group * group_ = group;
  int  ret = MPI_Comm_group(comm_, group_);
  comm = comm_;
  group = group_;
  return ret; }

int mpi_Iexscan(const void *sendbuf, void *recvbuf, int count, void *datatype, void *op, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Iexscan(sendbuf, recvbuf, count, datatype_, op_, comm_, request_);
  datatype = datatype_;
  op = op_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_create_hvector(int count, int blocklength, void *stride, void *oldtype, void **newtype) {
  MPI_Aint stride_ = stride;
  MPI_Datatype oldtype_ = oldtype;
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_create_hvector(count, blocklength, stride_, oldtype_, newtype_);
  stride = stride_;
  oldtype = oldtype_;
  newtype = newtype_;
  return ret; }

int mpi_Comm_idup(void *comm, void **newcomm, void **request) {
  MPI_Comm comm_ = comm;
  MPI_Comm * newcomm_ = newcomm;
  MPI_Request * request_ = request;
  int  ret = MPI_Comm_idup(comm_, newcomm_, request_);
  comm = comm_;
  newcomm = newcomm_;
  request = request_;
  return ret; }

int mpi_Igather(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, int recvcount, void *recvtype, int root, void *comm, void **request) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Igather(sendbuf, sendcount, sendtype_, recvbuf, recvcount, recvtype_, root, comm_, request_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[], void *oldtype, void **newtype) {
  MPI_Datatype oldtype_ = oldtype;
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_create_indexed_block(count, blocklength, array_of_displacements, oldtype_, newtype_);
  oldtype = oldtype_;
  newtype = newtype_;
  return ret; }

int mpi_Comm_join(int fd, void **intercomm) {
  MPI_Comm * intercomm_ = intercomm;
  int  ret = MPI_Comm_join(fd, intercomm_);
  intercomm = intercomm_;
  return ret; }

int mpi_Igatherv(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, const int recvcounts[], const int displs[], void *recvtype, int root, void *comm, void **request) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Igatherv(sendbuf, sendcount, sendtype_, recvbuf, recvcounts, displs, recvtype_, root, comm_, request_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_create_keyval(void **type_copy_attr_fn, void **type_delete_attr_fn, int *type_keyval, void *extra_state) {
  MPI_Type_copy_attr_function * type_copy_attr_fn_ = type_copy_attr_fn;
  MPI_Type_delete_attr_function * type_delete_attr_fn_ = type_delete_attr_fn;
  int  ret = MPI_Type_create_keyval(type_copy_attr_fn_, type_delete_attr_fn_, type_keyval, extra_state);
  type_copy_attr_fn = type_copy_attr_fn_;
  type_delete_attr_fn = type_delete_attr_fn_;
  return ret; }

int mpi_Comm_rank(void *comm, int *rank) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Comm_rank(comm_, rank);
  comm = comm_;
  return ret; }

int mpi_Improbe(int source, int tag, void *comm, int *flag, void **message, struct {long a,b,c; }*status) {
  MPI_Comm comm_ = comm;
  MPI_Message * message_ = message;
  MPI_Status * status_ = status;
  int  ret = MPI_Improbe(source, tag, comm_, flag, message_, status_);
  comm = comm_;
  message = message_;
  status = status_;
  return ret; }

int mpi_Type_create_resized(void *oldtype, void *lb, void *extent, void **newtype) {
  MPI_Datatype oldtype_ = oldtype;
  MPI_Aint lb_ = lb;
  MPI_Aint extent_ = extent;
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_create_resized(oldtype_, lb_, extent_, newtype_);
  oldtype = oldtype_;
  lb = lb_;
  extent = extent_;
  newtype = newtype_;
  return ret; }

int mpi_Comm_remote_group(void *comm, void **group) {
  MPI_Comm comm_ = comm;
  MPI_Group * group_ = group;
  int  ret = MPI_Comm_remote_group(comm_, group_);
  comm = comm_;
  group = group_;
  return ret; }

int mpi_Imrecv(void *buf, int count, void *datatype, void **message, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Message * message_ = message;
  MPI_Request * request_ = request;
  int  ret = MPI_Imrecv(buf, count, datatype_, message_, request_);
  datatype = datatype_;
  message = message_;
  request = request_;
  return ret; }

int mpi_Type_create_struct(int count, const int array_of_blocklengths[], const void *array_of_displacements[], const void *array_of_types[], void **newtype) {
  MPI_Aint array_of_displacements_[count];
  MPI_Datatype array_of_types_[count];
  MPI_Datatype * newtype_ = newtype;
  for (int i=0;i<count;++i){
    array_of_displacements_[i] = array_of_displacements[i];
    array_of_types_[i] = array_of_types[i];
  }
  int  ret = MPI_Type_create_struct(count, array_of_blocklengths, array_of_displacements_, array_of_types_, newtype_);
  for (int i=0;i<count;++i){
    array_of_displacements_[i] = array_of_displacements[i];
    array_of_types_[i] = array_of_types[i];
  }
  newtype = newtype_;
  return ret; }

int mpi_Comm_remote_size(void *comm, int *size) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Comm_remote_size(comm_, size);
  comm = comm_;
  return ret; }

int mpi_Ineighbor_allgather(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, int recvcount, void *recvtype, void *comm, void **request) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ineighbor_allgather(sendbuf, sendcount, sendtype_, recvbuf, recvcount, recvtype_, comm_, request_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[], const int array_of_starts[], int order, void *oldtype, void **newtype) {
  MPI_Datatype oldtype_ = oldtype;
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype_, newtype_);
  oldtype = oldtype_;
  newtype = newtype_;
  return ret; }

int mpi_Comm_set_attr(void *comm, int comm_keyval, void *attribute_val) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Comm_set_attr(comm_, comm_keyval, attribute_val);
  comm = comm_;
  return ret; }

int mpi_Ineighbor_allgatherv(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, const int recvcounts[], const int displs[], void *recvtype, void *comm, void **request) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype_, recvbuf, recvcounts, displs, recvtype_, comm_, request_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_delete_attr(void *datatype, int type_keyval) {
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_Type_delete_attr(datatype_, type_keyval);
  datatype = datatype_;
  return ret; }

int mpi_Comm_set_errhandler(void *comm, void *errhandler) {
  MPI_Comm comm_ = comm;
  MPI_Errhandler errhandler_ = errhandler;
  int  ret = MPI_Comm_set_errhandler(comm_, errhandler_);
  comm = comm_;
  errhandler = errhandler_;
  return ret; }

int mpi_Ineighbor_alltoall(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, int recvcount, void *recvtype, void *comm, void **request) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ineighbor_alltoall(sendbuf, sendcount, sendtype_, recvbuf, recvcount, recvtype_, comm_, request_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_dup(void *oldtype, void **newtype) {
  MPI_Datatype oldtype_ = oldtype;
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_dup(oldtype_, newtype_);
  oldtype = oldtype_;
  newtype = newtype_;
  return ret; }

int mpi_Comm_set_info(void *comm, void *info) {
  MPI_Comm comm_ = comm;
  MPI_Info info_ = info;
  int  ret = MPI_Comm_set_info(comm_, info_);
  comm = comm_;
  info = info_;
  return ret; }

int mpi_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], void *sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], void *recvtype, void *comm, void **request) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype_, recvbuf, recvcounts, rdispls, recvtype_, comm_, request_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_extent(void *datatype, void **extent) {
  MPI_Datatype datatype_ = datatype;
  MPI_Aint * extent_ = extent;
  int  ret = MPI_Type_extent(datatype_, extent_);
  datatype = datatype_;
  extent = extent_;
  return ret; }

int mpi_Comm_set_name(void *comm, const char *comm_name) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Comm_set_name(comm_, comm_name);
  comm = comm_;
  return ret; }

int mpi_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[], const void *sdispls[], const void *sendtypes[], void *recvbuf, const int recvcounts[], const void *rdispls[], const void *recvtypes[], void *comm, void **request) {
fprintf(stderr, "MPI_Ineighbor_alltoallw is not implementented in MultiMPI - use MPI directly\n");
MPI_Abort(MPI_COMM_WORLD, 1);
fprintf(stderr, "MPI_Ineighbor_alltoallw is not implementented in MultiMPI - use MPI directly\n");
MPI_Abort(MPI_COMM_WORLD, 1);
fprintf(stderr, "MPI_Ineighbor_alltoallw is not implementented in MultiMPI - use MPI directly\n");
MPI_Abort(MPI_COMM_WORLD, 1);
fprintf(stderr, "MPI_Ineighbor_alltoallw is not implementented in MultiMPI - use MPI directly\n");
MPI_Abort(MPI_COMM_WORLD, 1);
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_, request_);
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_free(void **datatype) {
  MPI_Datatype * datatype_ = datatype;
  int  ret = MPI_Type_free(datatype_);
  datatype = datatype_;
  return ret; }

int mpi_Comm_size(void *comm, int *size) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Comm_size(comm_, size);
  comm = comm_;
  return ret; }

int mpi_Info_create(void **info) {
  MPI_Info * info_ = info;
  int  ret = MPI_Info_create(info_);
  info = info_;
  return ret; }

int mpi_Type_free_keyval(int *type_keyval) {
  int  ret = MPI_Type_free_keyval(type_keyval);
  return ret; }

int mpi_Comm_spawn(const char *command, char *argv[], int maxprocs, void *info, int root, void *comm, void **intercomm, int array_of_errcodes[]) {
  MPI_Info info_ = info;
  MPI_Comm comm_ = comm;
  MPI_Comm * intercomm_ = intercomm;
  int  ret = MPI_Comm_spawn(command, argv, maxprocs, info_, root, comm_, intercomm_, array_of_errcodes);
  info = info_;
  comm = comm_;
  intercomm = intercomm_;
  return ret; }

int mpi_Info_delete(void *info, const char *key) {
  MPI_Info info_ = info;
  int  ret = MPI_Info_delete(info_, key);
  info = info_;
  return ret; }

int mpi_Type_get_attr(void *datatype, int type_keyval, void *attribute_val, int *flag) {
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_Type_get_attr(datatype_, type_keyval, attribute_val, flag);
  datatype = datatype_;
  return ret; }

int mpi_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], const int array_of_maxprocs[], const void *array_of_info[], int root, void *comm, void **intercomm, int array_of_errcodes[]) {
  MPI_Info array_of_info_[count];
  MPI_Comm comm_ = comm;
  MPI_Comm * intercomm_ = intercomm;
  for (int i=0;i<count;++i){
    array_of_info_[i] = array_of_info[i];
  }
  int  ret = MPI_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info_, root, comm_, intercomm_, array_of_errcodes);
  for (int i=0;i<count;++i){
    array_of_info_[i] = array_of_info[i];
  }
  comm = comm_;
  intercomm = intercomm_;
  return ret; }

int mpi_Info_dup(void *info, void **newinfo) {
  MPI_Info info_ = info;
  MPI_Info * newinfo_ = newinfo;
  int  ret = MPI_Info_dup(info_, newinfo_);
  info = info_;
  newinfo = newinfo_;
  return ret; }

int mpi_Type_get_contents(void *datatype, int max_integers, int max_addresses, int max_datatypes, int array_of_integers[], void *array_of_addresses[], void *array_of_datatypes[]) {
  MPI_Datatype datatype_ = datatype;
  MPI_Aint array_of_addresses_[max_addresses];
  MPI_Datatype array_of_datatypes_[max_datatypes];
  for (int i=0;i<max_addresses;++i){
    array_of_addresses_[i] = array_of_addresses[i];
  }
  for (int i=0;i<max_datatypes;++i){
    array_of_datatypes_[i] = array_of_datatypes[i];
  }
  int  ret = MPI_Type_get_contents(datatype_, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses_, array_of_datatypes_);
  for (int i=0;i<max_addresses;++i){
    array_of_addresses_[i] = array_of_addresses[i];
  }
  for (int i=0;i<max_datatypes;++i){
    array_of_datatypes_[i] = array_of_datatypes[i];
  }
  datatype = datatype_;
  return ret; }

int mpi_Comm_split(void *comm, int color, int key, void **newcomm) {
  MPI_Comm comm_ = comm;
  MPI_Comm * newcomm_ = newcomm;
  int  ret = MPI_Comm_split(comm_, color, key, newcomm_);
  comm = comm_;
  newcomm = newcomm_;
  return ret; }

int mpi_Info_free(void **info) {
  MPI_Info * info_ = info;
  int  ret = MPI_Info_free(info_);
  info = info_;
  return ret; }

int mpi_Type_get_envelope(void *datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner) {
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_Type_get_envelope(datatype_, num_integers, num_addresses, num_datatypes, combiner);
  datatype = datatype_;
  return ret; }

int mpi_Comm_split_type(void *comm, int split_type, int key, void *info, void ** newcomm) {
  MPI_Comm comm_ = comm;
  MPI_Info info_ = info;
  MPI_Comm * newcomm_ = newcomm;
  int  ret = MPI_Comm_split_type(comm_, split_type, key, info_, newcomm_);
  comm = comm_;
  info = info_;
  newcomm = newcomm_;
  return ret; }

int mpi_Info_get(void *info, const char *key, int valuelen, char *value, int *flag) {
  MPI_Info info_ = info;
  int  ret = MPI_Info_get(info_, key, valuelen, value, flag);
  info = info_;
  return ret; }

int mpi_Type_get_extent(void *datatype, void **lb, void **extent) {
  MPI_Datatype datatype_ = datatype;
  MPI_Aint * lb_ = lb;
  MPI_Aint * extent_ = extent;
  int  ret = MPI_Type_get_extent(datatype_, lb_, extent_);
  datatype = datatype_;
  lb = lb_;
  extent = extent_;
  return ret; }

int mpi_Comm_test_inter(void *comm, int *flag) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Comm_test_inter(comm_, flag);
  comm = comm_;
  return ret; }

int mpi_Info_get_nkeys(void *info, int *nkeys) {
  MPI_Info info_ = info;
  int  ret = MPI_Info_get_nkeys(info_, nkeys);
  info = info_;
  return ret; }

int mpi_Type_get_extent_x(void *datatype, void **lb, void **extent) {
  MPI_Datatype datatype_ = datatype;
  MPI_Count * lb_ = lb;
  MPI_Count * extent_ = extent;
  int  ret = MPI_Type_get_extent_x(datatype_, lb_, extent_);
  datatype = datatype_;
  lb = lb_;
  extent = extent_;
  return ret; }

int mpi_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr, void *datatype, int target_rank, void *target_disp, void *win) {
  MPI_Datatype datatype_ = datatype;
  MPI_Aint target_disp_ = target_disp;
  MPI_Win win_ = win;
  int  ret = MPI_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype_, target_rank, target_disp_, win_);
  datatype = datatype_;
  target_disp = target_disp_;
  win = win_;
  return ret; }

int mpi_Info_get_nthkey(void *info, int n, char *key) {
  MPI_Info info_ = info;
  int  ret = MPI_Info_get_nthkey(info_, n, key);
  info = info_;
  return ret; }

int mpi_Type_get_name(void *datatype, char *type_name, int *resultlen) {
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_Type_get_name(datatype_, type_name, resultlen);
  datatype = datatype_;
  return ret; }

int mpi_Dims_create(int nnodes, int ndims, int dims[]) {
  int  ret = MPI_Dims_create(nnodes, ndims, dims);
  return ret; }

int mpi_Info_get_valuelen(void *info, const char *key, int *valuelen, int *flag) {
  MPI_Info info_ = info;
  int  ret = MPI_Info_get_valuelen(info_, key, valuelen, flag);
  info = info_;
  return ret; }

int mpi_Type_get_true_extent(void *datatype, void **true_lb, void **true_extent) {
  MPI_Datatype datatype_ = datatype;
  MPI_Aint * true_lb_ = true_lb;
  MPI_Aint * true_extent_ = true_extent;
  int  ret = MPI_Type_get_true_extent(datatype_, true_lb_, true_extent_);
  datatype = datatype_;
  true_lb = true_lb_;
  true_extent = true_extent_;
  return ret; }

int mpi_Dist_graph_create(void *comm_old, int n, const int sources[], const int degrees[], const int destinations[], const int weights[], void *info, int reorder, void **comm_dist_graph) {
  MPI_Comm comm_old_ = comm_old;
  MPI_Info info_ = info;
  MPI_Comm * comm_dist_graph_ = comm_dist_graph;
  int  ret = MPI_Dist_graph_create(comm_old_, n, sources, degrees, destinations, weights, info_, reorder, comm_dist_graph_);
  comm_old = comm_old_;
  info = info_;
  comm_dist_graph = comm_dist_graph_;
  return ret; }

int mpi_Info_set(void *info, const char *key, const char *value) {
  MPI_Info info_ = info;
  int  ret = MPI_Info_set(info_, key, value);
  info = info_;
  return ret; }

int mpi_Type_get_true_extent_x(void *datatype, void **true_lb, void **true_extent) {
  MPI_Datatype datatype_ = datatype;
  MPI_Count * true_lb_ = true_lb;
  MPI_Count * true_extent_ = true_extent;
  int  ret = MPI_Type_get_true_extent_x(datatype_, true_lb_, true_extent_);
  datatype = datatype_;
  true_lb = true_lb_;
  true_extent = true_extent_;
  return ret; }

int mpi_Dist_graph_create_adjacent(void *comm_old, int indegree, const int sources[], const int sourceweights[], int outdegree, const int destinations[], const int destweights[], void *info, int reorder, void **comm_dist_graph) {
  MPI_Comm comm_old_ = comm_old;
  MPI_Info info_ = info;
  MPI_Comm * comm_dist_graph_ = comm_dist_graph;
  int  ret = MPI_Dist_graph_create_adjacent(comm_old_, indegree, sources, sourceweights, outdegree, destinations, destweights, info_, reorder, comm_dist_graph_);
  comm_old = comm_old_;
  info = info_;
  comm_dist_graph = comm_dist_graph_;
  return ret; }

int mpi_Init(int *argc, char ***argv) {
  int  ret = MPI_Init(argc, argv);
  return ret; }

int mpi_Type_hindexed(int count, const int *array_of_blocklengths, const void **array_of_displacements, void *oldtype, void **newtype) {
  MPI_Aint array_of_displacements_[count];
  MPI_Datatype oldtype_ = oldtype;
  MPI_Datatype * newtype_ = newtype;
  for (int i=0;i<count;++i){
    array_of_displacements_[i] = array_of_displacements[i];
  }
  int  ret = MPI_Type_hindexed(count, array_of_blocklengths, array_of_displacements_, oldtype_, newtype_);
  for (int i=0;i<count;++i){
    array_of_displacements_[i] = array_of_displacements[i];
  }
  oldtype = oldtype_;
  newtype = newtype_;
  return ret; }

int mpi_Dist_graph_neighbors(void *comm, int maxindegree, int sources[], int sourceweights[], int maxoutdegree, int destinations[], int destweights[]) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Dist_graph_neighbors(comm_, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights);
  comm = comm_;
  return ret; }

int mpi_Init_thread(int *argc, char ***argv, int required, int *provided) {
  int  ret = MPI_Init_thread(argc, argv, required, provided);
  return ret; }

int mpi_Type_hvector(int count, int blocklength, void *stride, void *oldtype, void **newtype) {
  MPI_Aint stride_ = stride;
  MPI_Datatype oldtype_ = oldtype;
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_hvector(count, blocklength, stride_, oldtype_, newtype_);
  stride = stride_;
  oldtype = oldtype_;
  newtype = newtype_;
  return ret; }

int mpi_Dist_graph_neighbors_count(void *comm, int *indegree, int *outdegree, int *weighted) {
  MPI_Comm comm_ = comm;
  int  ret = MPI_Dist_graph_neighbors_count(comm_, indegree, outdegree, weighted);
  comm = comm_;
  return ret; }

int mpi_Initialized(int *flag) {
  int  ret = MPI_Initialized(flag);
  return ret; }

int mpi_Type_indexed(int count, const int *array_of_blocklengths, const int *array_of_displacements, void *oldtype, void **newtype) {
  MPI_Datatype oldtype_ = oldtype;
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype_, newtype_);
  oldtype = oldtype_;
  newtype = newtype_;
  return ret; }

int mpi_Errhandler_create(void **function, void **errhandler) {
  MPI_Handler_function * function_ = function;
  MPI_Errhandler * errhandler_ = errhandler;
  int  ret = MPI_Errhandler_create(function_, errhandler_);
  function = function_;
  errhandler = errhandler_;
  return ret; }

int mpi_Intercomm_create(void *local_comm, int local_leader, void *peer_comm, int remote_leader, int tag, void **newintercomm) {
  MPI_Comm local_comm_ = local_comm;
  MPI_Comm peer_comm_ = peer_comm;
  MPI_Comm * newintercomm_ = newintercomm;
  int  ret = MPI_Intercomm_create(local_comm_, local_leader, peer_comm_, remote_leader, tag, newintercomm_);
  local_comm = local_comm_;
  peer_comm = peer_comm_;
  newintercomm = newintercomm_;
  return ret; }

int mpi_Type_lb(void *datatype, void **displacement) {
  MPI_Datatype datatype_ = datatype;
  MPI_Aint * displacement_ = displacement;
  int  ret = MPI_Type_lb(datatype_, displacement_);
  datatype = datatype_;
  displacement = displacement_;
  return ret; }

int mpi_Errhandler_free(void **errhandler) {
  MPI_Errhandler * errhandler_ = errhandler;
  int  ret = MPI_Errhandler_free(errhandler_);
  errhandler = errhandler_;
  return ret; }

int mpi_Intercomm_merge(void *intercomm, int high, void **newintracomm) {
  MPI_Comm intercomm_ = intercomm;
  MPI_Comm * newintracomm_ = newintracomm;
  int  ret = MPI_Intercomm_merge(intercomm_, high, newintracomm_);
  intercomm = intercomm_;
  newintracomm = newintracomm_;
  return ret; }

int mpi_Type_match_size(int typeclass, int size, void **datatype) {
  MPI_Datatype * datatype_ = datatype;
  int  ret = MPI_Type_match_size(typeclass, size, datatype_);
  datatype = datatype_;
  return ret; }

int mpi_Errhandler_get(void *comm, void **errhandler) {
  MPI_Comm comm_ = comm;
  MPI_Errhandler * errhandler_ = errhandler;
  int  ret = MPI_Errhandler_get(comm_, errhandler_);
  comm = comm_;
  errhandler = errhandler_;
  return ret; }

int mpi_Iprobe(int source, int tag, void *comm, int *flag, struct {long a,b,c; }*status) {
  MPI_Comm comm_ = comm;
  MPI_Status * status_ = status;
  int  ret = MPI_Iprobe(source, tag, comm_, flag, status_);
  comm = comm_;
  status = status_;
  return ret; }

int mpi_Type_set_attr(void *datatype, int type_keyval, void *attribute_val) {
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_Type_set_attr(datatype_, type_keyval, attribute_val);
  datatype = datatype_;
  return ret; }

int mpi_Errhandler_set(void *comm, void *errhandler) {
  MPI_Comm comm_ = comm;
  MPI_Errhandler errhandler_ = errhandler;
  int  ret = MPI_Errhandler_set(comm_, errhandler_);
  comm = comm_;
  errhandler = errhandler_;
  return ret; }

int mpi_Irecv(void *buf, int count, void *datatype, int source, int tag, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Irecv(buf, count, datatype_, source, tag, comm_, request_);
  datatype = datatype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_set_name(void *datatype, const char *type_name) {
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_Type_set_name(datatype_, type_name);
  datatype = datatype_;
  return ret; }

int mpi_Error_class(int errorcode, int *errorclass) {
  int  ret = MPI_Error_class(errorcode, errorclass);
  return ret; }

int mpi_Ireduce(const void *sendbuf, void *recvbuf, int count, void *datatype, void *op, int root, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ireduce(sendbuf, recvbuf, count, datatype_, op_, root, comm_, request_);
  datatype = datatype_;
  op = op_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_size(void *datatype, int *size) {
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_Type_size(datatype_, size);
  datatype = datatype_;
  return ret; }

int mpi_Error_string(int errorcode, char *string, int *resultlen) {
  int  ret = MPI_Error_string(errorcode, string, resultlen);
  return ret; }

int mpi_Ireduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], void *datatype, void *op, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype_, op_, comm_, request_);
  datatype = datatype_;
  op = op_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_size_x(void *datatype, void **size) {
  MPI_Datatype datatype_ = datatype;
  MPI_Count * size_ = size;
  int  ret = MPI_Type_size_x(datatype_, size_);
  datatype = datatype_;
  size = size_;
  return ret; }

int mpi_Exscan(const void *sendbuf, void *recvbuf, int count, void *datatype, void *op, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Exscan(sendbuf, recvbuf, count, datatype_, op_, comm_);
  datatype = datatype_;
  op = op_;
  comm = comm_;
  return ret; }

int mpi_Ireduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, void *datatype, void *op, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype_, op_, comm_, request_);
  datatype = datatype_;
  op = op_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_struct(int count, const int *array_of_blocklengths, const void **array_of_displacements, const void **array_of_types, void **newtype) {
  MPI_Aint array_of_displacements_[count];
  MPI_Datatype array_of_types_[count];
  MPI_Datatype * newtype_ = newtype;
  for (int i=0;i<count;++i){
    array_of_displacements_[i] = array_of_displacements[i];
    array_of_types_[i] = array_of_types[i];
  }
  int  ret = MPI_Type_struct(count, array_of_blocklengths, array_of_displacements_, array_of_types_, newtype_);
  for (int i=0;i<count;++i){
    array_of_displacements_[i] = array_of_displacements[i];
    array_of_types_[i] = array_of_types[i];
  }
  newtype = newtype_;
  return ret; }

int mpi_Fetch_and_op(const void *origin_addr, void *result_addr, void *datatype, int target_rank, void *target_disp, void *op, void *win) {
  MPI_Datatype datatype_ = datatype;
  MPI_Aint target_disp_ = target_disp;
  MPI_Op op_ = op;
  MPI_Win win_ = win;
  int  ret = MPI_Fetch_and_op(origin_addr, result_addr, datatype_, target_rank, target_disp_, op_, win_);
  datatype = datatype_;
  target_disp = target_disp_;
  op = op_;
  win = win_;
  return ret; }

int mpi_Irsend(const void *buf, int count, void *datatype, int dest, int tag, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Irsend(buf, count, datatype_, dest, tag, comm_, request_);
  datatype = datatype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Type_ub(void *datatype, void **displacement) {
  MPI_Datatype datatype_ = datatype;
  MPI_Aint * displacement_ = displacement;
  int  ret = MPI_Type_ub(datatype_, displacement_);
  datatype = datatype_;
  displacement = displacement_;
  return ret; }

MPI_Fint mpi_File_c2f(void *fh) {
  MPI_File fh_ = fh;
  MPI_Fint  ret = MPI_File_c2f(fh_);
  fh = fh_;
  return ret; }

int mpi_Is_thread_main(int *flag) {
  int  ret = MPI_Is_thread_main(flag);
  return ret; }

int mpi_Type_vector(int count, int blocklength, int stride, void *oldtype, void **newtype) {
  MPI_Datatype oldtype_ = oldtype;
  MPI_Datatype * newtype_ = newtype;
  int  ret = MPI_Type_vector(count, blocklength, stride, oldtype_, newtype_);
  oldtype = oldtype_;
  newtype = newtype_;
  return ret; }

int mpi_File_call_errhandler(void *fh, int errorcode) {
  MPI_File fh_ = fh;
  int  ret = MPI_File_call_errhandler(fh_, errorcode);
  fh = fh_;
  return ret; }

int mpi_Iscan(const void *sendbuf, void *recvbuf, int count, void *datatype, void *op, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Iscan(sendbuf, recvbuf, count, datatype_, op_, comm_, request_);
  datatype = datatype_;
  op = op_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount, void *datatype, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Unpack(inbuf, insize, position, outbuf, outcount, datatype_, comm_);
  datatype = datatype_;
  comm = comm_;
  return ret; }

int mpi_File_close(void **fh) {
  MPI_File * fh_ = fh;
  int  ret = MPI_File_close(fh_);
  fh = fh_;
  return ret; }

int mpi_Iscatter(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, int recvcount, void *recvtype, int root, void *comm, void **request) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Iscatter(sendbuf, sendcount, sendtype_, recvbuf, recvcount, recvtype_, root, comm_, request_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Unpack_external(const char datarep[], const void *inbuf, void *insize, void **position, void *outbuf, int outcount, void *datatype) {
  MPI_Aint insize_ = insize;
  MPI_Aint * position_ = position;
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_Unpack_external(datarep, inbuf, insize_, position_, outbuf, outcount, datatype_);
  insize = insize_;
  position = position_;
  datatype = datatype_;
  return ret; }

int mpi_File_create_errhandler(void **file_errhandler_fn, void **errhandler) {
  MPI_File_errhandler_function * file_errhandler_fn_ = file_errhandler_fn;
  MPI_Errhandler * errhandler_ = errhandler;
  int  ret = MPI_File_create_errhandler(file_errhandler_fn_, errhandler_);
  file_errhandler_fn = file_errhandler_fn_;
  errhandler = errhandler_;
  return ret; }

int mpi_Iscatterv(const void *sendbuf, const int sendcounts[], const int displs[], void *sendtype, void *recvbuf, int recvcount, void *recvtype, int root, void *comm, void **request) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Iscatterv(sendbuf, sendcounts, displs, sendtype_, recvbuf, recvcount, recvtype_, root, comm_, request_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Unpublish_name(const char *service_name, void *info, const char *port_name) {
  MPI_Info info_ = info;
  int  ret = MPI_Unpublish_name(service_name, info_, port_name);
  info = info_;
  return ret; }

int mpi_File_delete(char *filename, void *info) {
  MPI_Info info_ = info;
  int  ret = MPI_File_delete(filename, info_);
  info = info_;
  return ret; }

int mpi_Isend(const void *buf, int count, void *datatype, int dest, int tag, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Isend(buf, count, datatype_, dest, tag, comm_, request_);
  datatype = datatype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Wait(void **request, struct {long a,b,c; }*status) {
  MPI_Request * request_ = request;
  MPI_Status * status_ = status;
  int  ret = MPI_Wait(request_, status_);
  request = request_;
  status = status_;
  return ret; }

MPI_File mpi_File_f2c(void *fh) {
  MPI_Fint fh_ = fh;
  MPI_File  ret = MPI_File_f2c(fh_);
  fh = fh_;
  return ret; }

int mpi_Issend(const void *buf, int count, void *datatype, int dest, int tag, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Issend(buf, count, datatype_, dest, tag, comm_, request_);
  datatype = datatype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Waitall(int count, void *array_of_requests[], struct {long a,b,c; }array_of_statuses[]) {
  MPI_Request array_of_requests_[count];
  MPI_Status array_of_statuses_[count];
  for (int i=0;i<count;++i){
    array_of_requests_[i] = array_of_requests[i];

    char * a = array_of_statuses_ + i;
    char * b = array_of_statuses + i;
    int j=0;
    for (;j<sizeof(MPI_Status); ++j){
      a[j] = b[j];
    }

  }
  int  ret = MPI_Waitall(count, array_of_requests_, array_of_statuses_);
  for (int i=0;i<count;++i){
    array_of_requests_[i] = array_of_requests[i];

    char * a = array_of_statuses + i;
    char * b = array_of_statuses_ + i;
    int j=0;
    for (;j<sizeof(MPI_Status); ++j){
      a[j] = b[j];
    }


    for (;j<sizeof(struct {long a,b,c; }); ++j){
      a[j] = b[j];
    }
    
  }
  return ret; }

int mpi_File_get_amode(void *fh, int *amode) {
  MPI_File fh_ = fh;
  int  ret = MPI_File_get_amode(fh_, amode);
  fh = fh_;
  return ret; }

int mpi_Keyval_create(void **copy_fn, void **delete_fn, int *keyval, void *extra_state) {
  MPI_Copy_function * copy_fn_ = copy_fn;
  MPI_Delete_function * delete_fn_ = delete_fn;
  int  ret = MPI_Keyval_create(copy_fn_, delete_fn_, keyval, extra_state);
  copy_fn = copy_fn_;
  delete_fn = delete_fn_;
  return ret; }

int mpi_Waitany(int count, void *array_of_requests[], int *indx, struct {long a,b,c; }*status) {
  MPI_Request array_of_requests_[count];
  MPI_Status * status_ = status;
  for (int i=0;i<count;++i){
    array_of_requests_[i] = array_of_requests[i];
  }
  int  ret = MPI_Waitany(count, array_of_requests_, indx, status_);
  for (int i=0;i<count;++i){
    array_of_requests_[i] = array_of_requests[i];
  }
  status = status_;
  return ret; }

int mpi_File_get_atomicity(void *fh, int *flag) {
  MPI_File fh_ = fh;
  int  ret = MPI_File_get_atomicity(fh_, flag);
  fh = fh_;
  return ret; }

int mpi_Keyval_free(int *keyval) {
  int  ret = MPI_Keyval_free(keyval);
  return ret; }

int mpi_Waitsome(int incount, void *array_of_requests[], int *outcount, int array_of_indices[], struct {long a,b,c; }array_of_statuses[]) {
  MPI_Request array_of_requests_[incount];
  MPI_Status array_of_statuses_[*outcount];
  for (int i=0;i<incount;++i){
    array_of_requests_[i] = array_of_requests[i];
  }
  for (int i=0;i<*outcount;++i){

    char * a = array_of_statuses_ + i;
    char * b = array_of_statuses + i;
    int j=0;
    for (;j<sizeof(MPI_Status); ++j){
      a[j] = b[j];
    }

  }
  int  ret = MPI_Waitsome(incount, array_of_requests_, outcount, array_of_indices, array_of_statuses_);
  for (int i=0;i<incount;++i){
    array_of_requests_[i] = array_of_requests[i];
  }
  for (int i=0;i<*outcount;++i){

    char * a = array_of_statuses + i;
    char * b = array_of_statuses_ + i;
    int j=0;
    for (;j<sizeof(MPI_Status); ++j){
      a[j] = b[j];
    }


    for (;j<sizeof(struct {long a,b,c; }); ++j){
      a[j] = b[j];
    }
    
  }
  return ret; }

int mpi_File_get_byte_offset(void *fh, void *offset, void **disp) {
  MPI_File fh_ = fh;
  MPI_Offset offset_ = offset;
  MPI_Offset * disp_ = disp;
  int  ret = MPI_File_get_byte_offset(fh_, offset_, disp_);
  fh = fh_;
  offset = offset_;
  disp = disp_;
  return ret; }

int mpi_Lookup_name(const char *service_name, void *info, char *port_name) {
  MPI_Info info_ = info;
  int  ret = MPI_Lookup_name(service_name, info_, port_name);
  info = info_;
  return ret; }

int mpi_Win_allocate(void *size, int disp_unit, void *info, void *comm, void *baseptr, void **win) {
  MPI_Aint size_ = size;
  MPI_Info info_ = info;
  MPI_Comm comm_ = comm;
  MPI_Win * win_ = win;
  int  ret = MPI_Win_allocate(size_, disp_unit, info_, comm_, baseptr, win_);
  size = size_;
  info = info_;
  comm = comm_;
  win = win_;
  return ret; }

int mpi_File_get_errhandler(void *file, void **errhandler) {
  MPI_File file_ = file;
  MPI_Errhandler * errhandler_ = errhandler;
  int  ret = MPI_File_get_errhandler(file_, errhandler_);
  file = file_;
  errhandler = errhandler_;
  return ret; }

int mpi_Mprobe(int source, int tag, void *comm, void **message, struct {long a,b,c; }*status) {
  MPI_Comm comm_ = comm;
  MPI_Message * message_ = message;
  MPI_Status * status_ = status;
  int  ret = MPI_Mprobe(source, tag, comm_, message_, status_);
  comm = comm_;
  message = message_;
  status = status_;
  return ret; }

int mpi_Win_allocate_shared(void *size, int disp_unit, void *info, void *comm, void *baseptr, void **win) {
  MPI_Aint size_ = size;
  MPI_Info info_ = info;
  MPI_Comm comm_ = comm;
  MPI_Win * win_ = win;
  int  ret = MPI_Win_allocate_shared(size_, disp_unit, info_, comm_, baseptr, win_);
  size = size_;
  info = info_;
  comm = comm_;
  win = win_;
  return ret; }

int mpi_File_get_group(void *fh, void **group) {
  MPI_File fh_ = fh;
  MPI_Group * group_ = group;
  int  ret = MPI_File_get_group(fh_, group_);
  fh = fh_;
  group = group_;
  return ret; }

int mpi_Mrecv(void *buf, int count, void *datatype, void **message, struct {long a,b,c; }*status) {
  MPI_Datatype datatype_ = datatype;
  MPI_Message * message_ = message;
  MPI_Status * status_ = status;
  int  ret = MPI_Mrecv(buf, count, datatype_, message_, status_);
  datatype = datatype_;
  message = message_;
  status = status_;
  return ret; }

int mpi_Win_attach(void *win, void *base, void *size) {
  MPI_Win win_ = win;
  MPI_Aint size_ = size;
  int  ret = MPI_Win_attach(win_, base, size_);
  win = win_;
  size = size_;
  return ret; }

int mpi_File_get_info(void *fh, void **info_used) {
  MPI_File fh_ = fh;
  MPI_Info * info_used_ = info_used;
  int  ret = MPI_File_get_info(fh_, info_used_);
  fh = fh_;
  info_used = info_used_;
  return ret; }

int mpi_Neighbor_allgather(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, int recvcount, void *recvtype, void *comm) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Neighbor_allgather(sendbuf, sendcount, sendtype_, recvbuf, recvcount, recvtype_, comm_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  return ret; }

int mpi_Win_call_errhandler(void *win, int errorcode) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_call_errhandler(win_, errorcode);
  win = win_;
  return ret; }

int mpi_File_get_position(void *fh, void **offset) {
  MPI_File fh_ = fh;
  MPI_Offset * offset_ = offset;
  int  ret = MPI_File_get_position(fh_, offset_);
  fh = fh_;
  offset = offset_;
  return ret; }

int mpi_Neighbor_allgatherv(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, const int recvcounts[], const int displs[], void *recvtype, void *comm) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Neighbor_allgatherv(sendbuf, sendcount, sendtype_, recvbuf, recvcounts, displs, recvtype_, comm_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  return ret; }

int mpi_Win_complete(void *win) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_complete(win_);
  win = win_;
  return ret; }

int mpi_File_get_position_shared(void *fh, void **offset) {
  MPI_File fh_ = fh;
  MPI_Offset * offset_ = offset;
  int  ret = MPI_File_get_position_shared(fh_, offset_);
  fh = fh_;
  offset = offset_;
  return ret; }

int mpi_Neighbor_alltoall(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, int recvcount, void *recvtype, void *comm) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Neighbor_alltoall(sendbuf, sendcount, sendtype_, recvbuf, recvcount, recvtype_, comm_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  return ret; }

int mpi_Win_create(void *base, void *size, int disp_unit, void *info, void *comm, void **win) {
  MPI_Aint size_ = size;
  MPI_Info info_ = info;
  MPI_Comm comm_ = comm;
  MPI_Win * win_ = win;
  int  ret = MPI_Win_create(base, size_, disp_unit, info_, comm_, win_);
  size = size_;
  info = info_;
  comm = comm_;
  win = win_;
  return ret; }

int mpi_File_get_size(void *fh, void **size) {
  MPI_File fh_ = fh;
  MPI_Offset * size_ = size;
  int  ret = MPI_File_get_size(fh_, size_);
  fh = fh_;
  size = size_;
  return ret; }

int mpi_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[], void *sendtype, void *recvbuf, const int recvcounts[], const int rdispls[], void *recvtype, void *comm) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype_, recvbuf, recvcounts, rdispls, recvtype_, comm_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  return ret; }

int mpi_Win_create_dynamic(void *info, void *comm, void **win) {
  MPI_Info info_ = info;
  MPI_Comm comm_ = comm;
  MPI_Win * win_ = win;
  int  ret = MPI_Win_create_dynamic(info_, comm_, win_);
  info = info_;
  comm = comm_;
  win = win_;
  return ret; }

int mpi_File_get_type_extent(void *fh, void *datatype, void **extent) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPI_Aint * extent_ = extent;
  int  ret = MPI_File_get_type_extent(fh_, datatype_, extent_);
  fh = fh_;
  datatype = datatype_;
  extent = extent_;
  return ret; }

int mpi_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[], const void *sdispls[], const void *sendtypes[], void *recvbuf, const int recvcounts[], const void *rdispls[], const void *recvtypes[], void *comm) {
fprintf(stderr, "MPI_Neighbor_alltoallw is not implementented in MultiMPI - use MPI directly\n");
MPI_Abort(MPI_COMM_WORLD, 1);
fprintf(stderr, "MPI_Neighbor_alltoallw is not implementented in MultiMPI - use MPI directly\n");
MPI_Abort(MPI_COMM_WORLD, 1);
fprintf(stderr, "MPI_Neighbor_alltoallw is not implementented in MultiMPI - use MPI directly\n");
MPI_Abort(MPI_COMM_WORLD, 1);
fprintf(stderr, "MPI_Neighbor_alltoallw is not implementented in MultiMPI - use MPI directly\n");
MPI_Abort(MPI_COMM_WORLD, 1);
  MPI_Comm comm_ = comm;
  int  ret = MPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm_);
  comm = comm_;
  return ret; }

int mpi_Win_create_errhandler(void **win_errhandler_fn, void **errhandler) {
  MPI_Win_errhandler_function * win_errhandler_fn_ = win_errhandler_fn;
  MPI_Errhandler * errhandler_ = errhandler;
  int  ret = MPI_Win_create_errhandler(win_errhandler_fn_, errhandler_);
  win_errhandler_fn = win_errhandler_fn_;
  errhandler = errhandler_;
  return ret; }

int mpi_File_get_view(void *fh, void **disp, void **etype, void **filetype, char *datarep) {
  MPI_File fh_ = fh;
  MPI_Offset * disp_ = disp;
  MPI_Datatype * etype_ = etype;
  MPI_Datatype * filetype_ = filetype;
  int  ret = MPI_File_get_view(fh_, disp_, etype_, filetype_, datarep);
  fh = fh_;
  disp = disp_;
  etype = etype_;
  filetype = filetype_;
  return ret; }

int mpi_Op_commutative(void *op, int *commute) {
  MPI_Op op_ = op;
  int  ret = MPI_Op_commutative(op_, commute);
  op = op_;
  return ret; }

int mpi_Win_create_keyval(void **win_copy_attr_fn, void **win_delete_attr_fn, int *win_keyval, void *extra_state) {
  MPI_Win_copy_attr_function * win_copy_attr_fn_ = win_copy_attr_fn;
  MPI_Win_delete_attr_function * win_delete_attr_fn_ = win_delete_attr_fn;
  int  ret = MPI_Win_create_keyval(win_copy_attr_fn_, win_delete_attr_fn_, win_keyval, extra_state);
  win_copy_attr_fn = win_copy_attr_fn_;
  win_delete_attr_fn = win_delete_attr_fn_;
  return ret; }

int mpi_File_iread(void *fh, void *buf, int count, void *datatype, void **request) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPI_Request * request_ = request;
  int  ret = MPI_File_iread(fh_, buf, count, datatype_, request_);
  fh = fh_;
  datatype = datatype_;
  request = request_;
  return ret; }

int mpi_Op_create(void **user_fn, int commute, void **op) {
  MPI_User_function * user_fn_ = user_fn;
  MPI_Op * op_ = op;
  int  ret = MPI_Op_create(user_fn_, commute, op_);
  user_fn = user_fn_;
  op = op_;
  return ret; }

int mpi_Win_delete_attr(void *win, int win_keyval) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_delete_attr(win_, win_keyval);
  win = win_;
  return ret; }

int mpi_File_iread_at(void *fh, void *offset, void *buf, int count, void *datatype, void **request) {
  MPI_File fh_ = fh;
  MPI_Offset offset_ = offset;
  MPI_Datatype datatype_ = datatype;
  MPIO_Request * request_ = request;
  int  ret = MPI_File_iread_at(fh_, offset_, buf, count, datatype_, request_);
  fh = fh_;
  offset = offset_;
  datatype = datatype_;
  request = request_;
  return ret; }

int mpi_Op_free(void **op) {
  MPI_Op * op_ = op;
  int  ret = MPI_Op_free(op_);
  op = op_;
  return ret; }

int mpi_Win_detach(void *win, const void *base) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_detach(win_, base);
  win = win_;
  return ret; }

int mpi_File_iread_shared(void *fh, void *buf, int count, void *datatype, void **request) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPI_Request * request_ = request;
  int  ret = MPI_File_iread_shared(fh_, buf, count, datatype_, request_);
  fh = fh_;
  datatype = datatype_;
  request = request_;
  return ret; }

int mpi_Open_port(void *info, char *port_name) {
  MPI_Info info_ = info;
  int  ret = MPI_Open_port(info_, port_name);
  info = info_;
  return ret; }

int mpi_Win_fence(int assert, void *win) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_fence(assert, win_);
  win = win_;
  return ret; }

int mpi_File_iwrite(void *fh, void *buf, int count, void *datatype, void **request) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPI_Request * request_ = request;
  int  ret = MPI_File_iwrite(fh_, buf, count, datatype_, request_);
  fh = fh_;
  datatype = datatype_;
  request = request_;
  return ret; }

int mpi_Pack(const void *inbuf, int incount, void *datatype, void *outbuf, int outsize, int *position, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Pack(inbuf, incount, datatype_, outbuf, outsize, position, comm_);
  datatype = datatype_;
  comm = comm_;
  return ret; }

int mpi_Win_flush(int rank, void *win) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_flush(rank, win_);
  win = win_;
  return ret; }

int mpi_File_iwrite_at(void *fh, void *offset, void *buf, int count, void *datatype, void **request) {
  MPI_File fh_ = fh;
  MPI_Offset offset_ = offset;
  MPI_Datatype datatype_ = datatype;
  MPIO_Request * request_ = request;
  int  ret = MPI_File_iwrite_at(fh_, offset_, buf, count, datatype_, request_);
  fh = fh_;
  offset = offset_;
  datatype = datatype_;
  request = request_;
  return ret; }

int mpi_Pack_external(const char datarep[], const void *inbuf, int incount, void *datatype, void *outbuf, void *outsize, void **position) {
  MPI_Datatype datatype_ = datatype;
  MPI_Aint outsize_ = outsize;
  MPI_Aint * position_ = position;
  int  ret = MPI_Pack_external(datarep, inbuf, incount, datatype_, outbuf, outsize_, position_);
  datatype = datatype_;
  outsize = outsize_;
  position = position_;
  return ret; }

int mpi_Win_flush_all(void *win) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_flush_all(win_);
  win = win_;
  return ret; }

int mpi_File_iwrite_shared(void *fh, void *buf, int count, void *datatype, void **request) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPIO_Request * request_ = request;
  int  ret = MPI_File_iwrite_shared(fh_, buf, count, datatype_, request_);
  fh = fh_;
  datatype = datatype_;
  request = request_;
  return ret; }

int mpi_Pack_external_size(const char datarep[], int incount, void *datatype, void **size) {
  MPI_Datatype datatype_ = datatype;
  MPI_Aint * size_ = size;
  int  ret = MPI_Pack_external_size(datarep, incount, datatype_, size_);
  datatype = datatype_;
  size = size_;
  return ret; }

int mpi_Win_flush_local(int rank, void *win) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_flush_local(rank, win_);
  win = win_;
  return ret; }

int mpi_File_open(void *comm, char *filename, int amode, void *info, void **fh) {
  MPI_Comm comm_ = comm;
  MPI_Info info_ = info;
  MPI_File * fh_ = fh;
  int  ret = MPI_File_open(comm_, filename, amode, info_, fh_);
  comm = comm_;
  info = info_;
  fh = fh_;
  return ret; }

int mpi_Pack_size(int incount, void *datatype, void *comm, int *size) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Pack_size(incount, datatype_, comm_, size);
  datatype = datatype_;
  comm = comm_;
  return ret; }

int mpi_Win_flush_local_all(void *win) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_flush_local_all(win_);
  win = win_;
  return ret; }

int mpi_File_preallocate(void *fh, void *size) {
  MPI_File fh_ = fh;
  MPI_Offset size_ = size;
  int  ret = MPI_File_preallocate(fh_, size_);
  fh = fh_;
  size = size_;
  return ret; }

int mpi_Win_free(void **win) {
  MPI_Win * win_ = win;
  int  ret = MPI_Win_free(win_);
  win = win_;
  return ret; }

int mpi_File_read(void *fh, void *buf, int count, void *datatype, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPI_Status * status_ = status;
  int  ret = MPI_File_read(fh_, buf, count, datatype_, status_);
  fh = fh_;
  datatype = datatype_;
  status = status_;
  return ret; }

int mpi_Probe(int source, int tag, void *comm, struct {long a,b,c; }*status) {
  MPI_Comm comm_ = comm;
  MPI_Status * status_ = status;
  int  ret = MPI_Probe(source, tag, comm_, status_);
  comm = comm_;
  status = status_;
  return ret; }

int mpi_Win_free_keyval(int *win_keyval) {
  int  ret = MPI_Win_free_keyval(win_keyval);
  return ret; }

int mpi_File_read_all(void *fh, void *buf, int count, void *datatype, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPI_Status * status_ = status;
  int  ret = MPI_File_read_all(fh_, buf, count, datatype_, status_);
  fh = fh_;
  datatype = datatype_;
  status = status_;
  return ret; }

int mpi_Publish_name(const char *service_name, void *info, const char *port_name) {
  MPI_Info info_ = info;
  int  ret = MPI_Publish_name(service_name, info_, port_name);
  info = info_;
  return ret; }

int mpi_Win_get_attr(void *win, int win_keyval, void *attribute_val, int *flag) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_get_attr(win_, win_keyval, attribute_val, flag);
  win = win_;
  return ret; }

int mpi_File_read_all_begin(void *fh, void *buf, int count, void *datatype) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_File_read_all_begin(fh_, buf, count, datatype_);
  fh = fh_;
  datatype = datatype_;
  return ret; }

int mpi_Put(const void *origin_addr, int origin_count, MPI_Datatype
            origin_datatype, int target_rank, void *target_disp, int target_count, void *target_datatype, MPI_Win
            win) {
  MPI_Datatype origin_datatype_ = origin_datatype;
  MPI_Aint target_disp_ = target_disp;
  MPI_Datatype target_datatype_ = target_datatype;
  MPI_Win win_ = win;
  int  ret = MPI_Put(origin_addr, origin_count, origin_datatype_, target_rank, target_disp_, target_count, target_datatype_, win_);
  origin_datatype = origin_datatype_;
  target_disp = target_disp_;
  target_datatype = target_datatype_;
  win = win_;
  return ret; }

int mpi_Win_get_errhandler(void *win, void **errhandler) {
  MPI_Win win_ = win;
  MPI_Errhandler * errhandler_ = errhandler;
  int  ret = MPI_Win_get_errhandler(win_, errhandler_);
  win = win_;
  errhandler = errhandler_;
  return ret; }

int mpi_File_read_all_end(void *fh, void *buf, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Status * status_ = status;
  int  ret = MPI_File_read_all_end(fh_, buf, status_);
  fh = fh_;
  status = status_;
  return ret; }

int mpi_Query_thread(int *provided) {
  int  ret = MPI_Query_thread(provided);
  return ret; }

int mpi_Win_get_group(void *win, void **group) {
  MPI_Win win_ = win;
  MPI_Group * group_ = group;
  int  ret = MPI_Win_get_group(win_, group_);
  win = win_;
  group = group_;
  return ret; }

int mpi_File_read_at(void *fh, void *offset, void *buf, int count, void *datatype, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Offset offset_ = offset;
  MPI_Datatype datatype_ = datatype;
  MPI_Status * status_ = status;
  int  ret = MPI_File_read_at(fh_, offset_, buf, count, datatype_, status_);
  fh = fh_;
  offset = offset_;
  datatype = datatype_;
  status = status_;
  return ret; }

int mpi_Raccumulate(const void *origin_addr, int origin_count, MPI_Datatype
                   origin_datatype, int target_rank, MPI_Aint
                   target_disp, int target_count, MPI_Datatype
                   target_datatype, void *op, void *win, void **request) {
  MPI_Datatype origin_datatype_ = origin_datatype;
  MPI_Aint target_disp_ = target_disp;
  MPI_Datatype target_datatype_ = target_datatype;
  MPI_Op op_ = op;
  MPI_Win win_ = win;
  MPI_Request * request_ = request;
  int  ret = MPI_Raccumulate(origin_addr, origin_count, origin_datatype_, target_rank, target_disp_, target_count, target_datatype_, op_, win_, request_);
  origin_datatype = origin_datatype_;
  target_disp = target_disp_;
  target_datatype = target_datatype_;
  op = op_;
  win = win_;
  request = request_;
  return ret; }

int mpi_Win_get_info(void *win, void **info_used) {
  MPI_Win win_ = win;
  MPI_Info * info_used_ = info_used;
  int  ret = MPI_Win_get_info(win_, info_used_);
  win = win_;
  info_used = info_used_;
  return ret; }

int mpi_File_read_at_all(void *fh, void *offset, void *buf, int count, void *datatype, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Offset offset_ = offset;
  MPI_Datatype datatype_ = datatype;
  MPI_Status * status_ = status;
  int  ret = MPI_File_read_at_all(fh_, offset_, buf, count, datatype_, status_);
  fh = fh_;
  offset = offset_;
  datatype = datatype_;
  status = status_;
  return ret; }

int mpi_Recv(void *buf, int count, void *datatype, int source, int tag, void *comm, struct {long a,b,c; }*status) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Status * status_ = status;
  int  ret = MPI_Recv(buf, count, datatype_, source, tag, comm_, status_);
  datatype = datatype_;
  comm = comm_;
  status = status_;
  return ret; }

int mpi_Win_get_name(void *win, char *win_name, int *resultlen) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_get_name(win_, win_name, resultlen);
  win = win_;
  return ret; }

int mpi_File_read_at_all_begin(void *fh, void *offset, void *buf, int count, void *datatype) {
  MPI_File fh_ = fh;
  MPI_Offset offset_ = offset;
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_File_read_at_all_begin(fh_, offset_, buf, count, datatype_);
  fh = fh_;
  offset = offset_;
  datatype = datatype_;
  return ret; }

int mpi_Recv_init(void *buf, int count, void *datatype, int source, int tag, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Recv_init(buf, count, datatype_, source, tag, comm_, request_);
  datatype = datatype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Win_lock(int lock_type, int rank, int assert, void *win) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_lock(lock_type, rank, assert, win_);
  win = win_;
  return ret; }

int mpi_File_read_at_all_end(void *fh, void *buf, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Status * status_ = status;
  int  ret = MPI_File_read_at_all_end(fh_, buf, status_);
  fh = fh_;
  status = status_;
  return ret; }

int mpi_Reduce(const void *sendbuf, void *recvbuf, int count, void *datatype, void *op, int root, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Reduce(sendbuf, recvbuf, count, datatype_, op_, root, comm_);
  datatype = datatype_;
  op = op_;
  comm = comm_;
  return ret; }

int mpi_Win_lock_all(int assert, void *win) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_lock_all(assert, win_);
  win = win_;
  return ret; }

int mpi_File_read_ordered(void *fh, void *buf, int count, void *datatype, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPI_Status * status_ = status;
  int  ret = MPI_File_read_ordered(fh_, buf, count, datatype_, status_);
  fh = fh_;
  datatype = datatype_;
  status = status_;
  return ret; }

int mpi_Reduce_local(const void *inbuf, void *inoutbuf, int count, void *datatype, void *op) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  int  ret = MPI_Reduce_local(inbuf, inoutbuf, count, datatype_, op_);
  datatype = datatype_;
  op = op_;
  return ret; }

int mpi_Win_post(void *group, int assert, void *win) {
  MPI_Group group_ = group;
  MPI_Win win_ = win;
  int  ret = MPI_Win_post(group_, assert, win_);
  group = group_;
  win = win_;
  return ret; }

int mpi_File_read_ordered_begin(void *fh, void *buf, int count, void *datatype) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  int  ret = MPI_File_read_ordered_begin(fh_, buf, count, datatype_);
  fh = fh_;
  datatype = datatype_;
  return ret; }

int mpi_Reduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[], void *datatype, void *op, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype_, op_, comm_);
  datatype = datatype_;
  op = op_;
  comm = comm_;
  return ret; }

int mpi_Win_set_attr(void *win, int win_keyval, void *attribute_val) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_set_attr(win_, win_keyval, attribute_val);
  win = win_;
  return ret; }

int mpi_File_read_ordered_end(void *fh, void *buf, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Status * status_ = status;
  int  ret = MPI_File_read_ordered_end(fh_, buf, status_);
  fh = fh_;
  status = status_;
  return ret; }

int mpi_Reduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount, void *datatype, void *op, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype_, op_, comm_);
  datatype = datatype_;
  op = op_;
  comm = comm_;
  return ret; }

int mpi_Win_set_errhandler(void *win, void *errhandler) {
  MPI_Win win_ = win;
  MPI_Errhandler errhandler_ = errhandler;
  int  ret = MPI_Win_set_errhandler(win_, errhandler_);
  win = win_;
  errhandler = errhandler_;
  return ret; }

int mpi_File_read_shared(void *fh, void *buf, int count, void *datatype, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPI_Status * status_ = status;
  int  ret = MPI_File_read_shared(fh_, buf, count, datatype_, status_);
  fh = fh_;
  datatype = datatype_;
  status = status_;
  return ret; }

int mpi_Register_datarep(char *datarep, void **read_conversion_fn, void **write_conversion_fn, void **dtype_file_extent_fn, void *extra_state) {
  MPI_Datarep_conversion_function * read_conversion_fn_ = read_conversion_fn;
  MPI_Datarep_conversion_function * write_conversion_fn_ = write_conversion_fn;
  MPI_Datarep_extent_function * dtype_file_extent_fn_ = dtype_file_extent_fn;
  int  ret = MPI_Register_datarep(datarep, read_conversion_fn_, write_conversion_fn_, dtype_file_extent_fn_, extra_state);
  read_conversion_fn = read_conversion_fn_;
  write_conversion_fn = write_conversion_fn_;
  dtype_file_extent_fn = dtype_file_extent_fn_;
  return ret; }

int mpi_Win_set_info(void *win, void *info) {
  MPI_Win win_ = win;
  MPI_Info info_ = info;
  int  ret = MPI_Win_set_info(win_, info_);
  win = win_;
  info = info_;
  return ret; }

int mpi_File_seek(void *fh, void *offset, int whence) {
  MPI_File fh_ = fh;
  MPI_Offset offset_ = offset;
  int  ret = MPI_File_seek(fh_, offset_, whence);
  fh = fh_;
  offset = offset_;
  return ret; }

int mpi_Request_free(void **request) {
  MPI_Request * request_ = request;
  int  ret = MPI_Request_free(request_);
  request = request_;
  return ret; }

int mpi_Win_set_name(void *win, const char *win_name) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_set_name(win_, win_name);
  win = win_;
  return ret; }

int mpi_File_seek_shared(void *fh, void *offset, int whence) {
  MPI_File fh_ = fh;
  MPI_Offset offset_ = offset;
  int  ret = MPI_File_seek_shared(fh_, offset_, whence);
  fh = fh_;
  offset = offset_;
  return ret; }

int mpi_Request_get_status(void *request, int *flag, struct {long a,b,c; }*status) {
  MPI_Request request_ = request;
  MPI_Status * status_ = status;
  int  ret = MPI_Request_get_status(request_, flag, status_);
  request = request_;
  status = status_;
  return ret; }

int mpi_Win_shared_query(void *win, int rank, void **size, int *disp_unit, void *baseptr) {
  MPI_Win win_ = win;
  MPI_Aint * size_ = size;
  int  ret = MPI_Win_shared_query(win_, rank, size_, disp_unit, baseptr);
  win = win_;
  size = size_;
  return ret; }

int mpi_File_set_atomicity(void *fh, int flag) {
  MPI_File fh_ = fh;
  int  ret = MPI_File_set_atomicity(fh_, flag);
  fh = fh_;
  return ret; }

int mpi_Rget(void *origin_addr, int origin_count, MPI_Datatype
            origin_datatype, int target_rank, void *target_disp, int target_count, void *target_datatype, MPI_Win
            win, void **request) {
  MPI_Datatype origin_datatype_ = origin_datatype;
  MPI_Aint target_disp_ = target_disp;
  MPI_Datatype target_datatype_ = target_datatype;
  MPI_Win win_ = win;
  MPI_Request * request_ = request;
  int  ret = MPI_Rget(origin_addr, origin_count, origin_datatype_, target_rank, target_disp_, target_count, target_datatype_, win_, request_);
  origin_datatype = origin_datatype_;
  target_disp = target_disp_;
  target_datatype = target_datatype_;
  win = win_;
  request = request_;
  return ret; }

int mpi_Win_start(void *group, int assert, void *win) {
  MPI_Group group_ = group;
  MPI_Win win_ = win;
  int  ret = MPI_Win_start(group_, assert, win_);
  group = group_;
  win = win_;
  return ret; }

int mpi_File_set_errhandler(void *file, void *errhandler) {
  MPI_File file_ = file;
  MPI_Errhandler errhandler_ = errhandler;
  int  ret = MPI_File_set_errhandler(file_, errhandler_);
  file = file_;
  errhandler = errhandler_;
  return ret; }

int mpi_Rget_accumulate(const void *origin_addr, int origin_count, void *origin_datatype, void *result_addr, int result_count, void *result_datatype, int target_rank, void *target_disp, int target_count, void *target_datatype, void *op, void *win, void **request) {
  MPI_Datatype origin_datatype_ = origin_datatype;
  MPI_Datatype result_datatype_ = result_datatype;
  MPI_Aint target_disp_ = target_disp;
  MPI_Datatype target_datatype_ = target_datatype;
  MPI_Op op_ = op;
  MPI_Win win_ = win;
  MPI_Request * request_ = request;
  int  ret = MPI_Rget_accumulate(origin_addr, origin_count, origin_datatype_, result_addr, result_count, result_datatype_, target_rank, target_disp_, target_count, target_datatype_, op_, win_, request_);
  origin_datatype = origin_datatype_;
  result_datatype = result_datatype_;
  target_disp = target_disp_;
  target_datatype = target_datatype_;
  op = op_;
  win = win_;
  request = request_;
  return ret; }

int mpi_Win_sync(void *win) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_sync(win_);
  win = win_;
  return ret; }

int mpi_File_set_info(void *fh, void *info) {
  MPI_File fh_ = fh;
  MPI_Info info_ = info;
  int  ret = MPI_File_set_info(fh_, info_);
  fh = fh_;
  info = info_;
  return ret; }

int mpi_Rput(const void *origin_addr, int origin_count, MPI_Datatype
            origin_datatype, int target_rank, void *target_disp, int target_count, void *target_datatype, MPI_Win
            win, void **request) {
  MPI_Datatype origin_datatype_ = origin_datatype;
  MPI_Aint target_disp_ = target_disp;
  MPI_Datatype target_datatype_ = target_datatype;
  MPI_Win win_ = win;
  MPI_Request * request_ = request;
  int  ret = MPI_Rput(origin_addr, origin_count, origin_datatype_, target_rank, target_disp_, target_count, target_datatype_, win_, request_);
  origin_datatype = origin_datatype_;
  target_disp = target_disp_;
  target_datatype = target_datatype_;
  win = win_;
  request = request_;
  return ret; }

int mpi_Win_test(void *win, int *flag) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_test(win_, flag);
  win = win_;
  return ret; }

int mpi_File_set_size(void *fh, void *size) {
  MPI_File fh_ = fh;
  MPI_Offset size_ = size;
  int  ret = MPI_File_set_size(fh_, size_);
  fh = fh_;
  size = size_;
  return ret; }

int mpi_Rsend(const void *buf, int count, void *datatype, int dest, int tag, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Rsend(buf, count, datatype_, dest, tag, comm_);
  datatype = datatype_;
  comm = comm_;
  return ret; }

int mpi_Win_unlock(int rank, void *win) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_unlock(rank, win_);
  win = win_;
  return ret; }

int mpi_File_set_view(void *fh, void *disp, void *etype, void *filetype, char *datarep, void *info) {
  MPI_File fh_ = fh;
  MPI_Offset disp_ = disp;
  MPI_Datatype etype_ = etype;
  MPI_Datatype filetype_ = filetype;
  MPI_Info info_ = info;
  int  ret = MPI_File_set_view(fh_, disp_, etype_, filetype_, datarep, info_);
  fh = fh_;
  disp = disp_;
  etype = etype_;
  filetype = filetype_;
  info = info_;
  return ret; }

int mpi_Rsend_init(const void *buf, int count, void *datatype, int dest, int tag, void *comm, void **request) {
  MPI_Datatype datatype_ = datatype;
  MPI_Comm comm_ = comm;
  MPI_Request * request_ = request;
  int  ret = MPI_Rsend_init(buf, count, datatype_, dest, tag, comm_, request_);
  datatype = datatype_;
  comm = comm_;
  request = request_;
  return ret; }

int mpi_Win_unlock_all(void *win) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_unlock_all(win_);
  win = win_;
  return ret; }

int mpi_File_sync(void *fh) {
  MPI_File fh_ = fh;
  int  ret = MPI_File_sync(fh_);
  fh = fh_;
  return ret; }

int mpi_Scan(const void *sendbuf, void *recvbuf, int count, void *datatype, void *op, void *comm) {
  MPI_Datatype datatype_ = datatype;
  MPI_Op op_ = op;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Scan(sendbuf, recvbuf, count, datatype_, op_, comm_);
  datatype = datatype_;
  op = op_;
  comm = comm_;
  return ret; }

int mpi_Win_wait(void *win) {
  MPI_Win win_ = win;
  int  ret = MPI_Win_wait(win_);
  win = win_;
  return ret; }

int mpi_File_write(void *fh, void *buf, int count, void *datatype, struct {long a,b,c; }*status) {
  MPI_File fh_ = fh;
  MPI_Datatype datatype_ = datatype;
  MPI_Status * status_ = status;
  int  ret = MPI_File_write(fh_, buf, count, datatype_, status_);
  fh = fh_;
  datatype = datatype_;
  status = status_;
  return ret; }

int mpi_Scatter(const void *sendbuf, int sendcount, void *sendtype, void *recvbuf, int recvcount, void *recvtype, int root, void *comm) {
  MPI_Datatype sendtype_ = sendtype;
  MPI_Datatype recvtype_ = recvtype;
  MPI_Comm comm_ = comm;
  int  ret = MPI_Scatter(sendbuf, sendcount, sendtype_, recvbuf, recvcount, recvtype_, root, comm_);
  sendtype = sendtype_;
  recvtype = recvtype_;
  comm = comm_;
  return ret; }

double mpi_Wtick() {
  double  ret = MPI_Wtick();
  return ret; }

double mpi_Wtime() {
  double  ret = MPI_Wtime();
  return ret; }
