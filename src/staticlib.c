#include "dlfcn.h"
#include "mpi.h"
#include "stdio.h"

void *handle = 0;

MPI_Comm MPI_COMM_WORLD;
MPI_Comm MPI_COMM_NULL;
MPI_Datatype MPI_DOUBLE;
MPI_Datatype MPI_INT;
MPI_Datatype MPI_BYTE;
MPI_Datatype MPI_CHAR;
MPI_Datatype MPI_C_BOOL;
MPI_Datatype MPI_DOUBLE_COMPLEX;
MPI_Op MPI_MAX;
MPI_Op MPI_MIN;
MPI_Op MPI_SUM;
MPI_Op MPI_LOR;
MPI_Op MPI_BOR;
MPI_Op MPI_LAND;
MPI_Request MPI_REQUEST_NULL;
MPI_Group MPI_GROUP_EMPTY;
int MPI_SUCCESS;
int MPI_UNDEFINED;
MPI_Status *MPI_STATUS_IGNORE;

int multimpi_static_init() {
  if (handle)
    return 0;
  const char *mylib;

  handle = dlopen("libmpich.so.12", RTLD_NOW);
  if (handle) {
    dlclose(handle);
    mylib = "multimpi_mpichv31.so";
  } else {

    handle = dlopen("libmpi.so.12", RTLD_NOW);
    if (handle) {
      dlclose(handle);
      mylib = "multimpi_mpichv3x.so";
    } else {

      handle = dlopen("libmpi.so.0", RTLD_NOW);
      if (handle) {
        dlclose(handle);
        mylib = "multimpi_openmpiv13.so";
      } else {

        handle = dlopen("libmpi.so.1", RTLD_NOW);
        if (handle) {
          dlclose(handle);
          mylib = "multimpi_openmpiv17.so";
        } else {

          handle = dlopen("libmpi.so.1", RTLD_NOW);
          if (handle) {
            dlclose(handle);
            mylib = "multimpi_openmpiv15.so";
          } else {

            handle = dlopen("libmpi.so.20", RTLD_NOW);
            if (handle) {
              dlclose(handle);
              mylib = "multimpi_openmpiv20.so";
            } else {

              handle = dlopen("libmpi.so.40", RTLD_NOW);
              if (handle) {
                dlclose(handle);
                mylib = "multimpi_openmpiv30.so";
              } else {

                printf("could not find a suitable mpilibrary. Ensure "
                       "LD_LIBRARY_PATH is correct\n");
                return 1;
              }
            }
          }
        }
      }
    }
  }

  handle = dlopen(mylib, RTLD_NOW);
  if (!handle) {
    printf("could not dlopen: %s\n", dlerror());
    return 1;
  }
  typedef void (*dyn_init)(void);
  dyn_init func = (dyn_init)dlsym(handle, "multimpi_init");
  func();
  return 0;
}

int multimpi_MPI_Init(int *argc, char ***argv) {
  if (multimpi_static_init()) {
    printf("return early\n");
    return 1;
  }
  typedef int (*mpiinit)(int *, char ***);
  mpiinit func = (mpiinit)dlsym(handle, "mpi_Init");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }

  MPI_COMM_WORLD = *((MPI_Comm *)dlsym(handle, "mpi_COMM_WORLD"));
  MPI_COMM_NULL = *((MPI_Comm *)dlsym(handle, "mpi_COMM_NULL"));
  MPI_DOUBLE = *((MPI_Datatype *)dlsym(handle, "mpi_DOUBLE"));
  MPI_INT = *((MPI_Datatype *)dlsym(handle, "mpi_INT"));
  MPI_BYTE = *((MPI_Datatype *)dlsym(handle, "mpi_BYTE"));
  MPI_CHAR = *((MPI_Datatype *)dlsym(handle, "mpi_CHAR"));
  MPI_C_BOOL = *((MPI_Datatype *)dlsym(handle, "mpi_C_BOOL"));
  MPI_DOUBLE_COMPLEX = *((MPI_Datatype *)dlsym(handle, "mpi_DOUBLE_COMPLEX"));
  MPI_MAX = *((MPI_Op *)dlsym(handle, "mpi_MAX"));
  MPI_MIN = *((MPI_Op *)dlsym(handle, "mpi_MIN"));
  MPI_SUM = *((MPI_Op *)dlsym(handle, "mpi_SUM"));
  MPI_LOR = *((MPI_Op *)dlsym(handle, "mpi_LOR"));
  MPI_BOR = *((MPI_Op *)dlsym(handle, "mpi_BOR"));
  MPI_LAND = *((MPI_Op *)dlsym(handle, "mpi_LAND"));
  MPI_REQUEST_NULL = *((MPI_Request *)dlsym(handle, "mpi_REQUEST_NULL"));
  MPI_GROUP_EMPTY = *((MPI_Group *)dlsym(handle, "mpi_GROUP_EMPTY"));
  MPI_SUCCESS = *((int *)dlsym(handle, "mpi_SUCCESS"));
  MPI_UNDEFINED = *((int *)dlsym(handle, "mpi_UNDEFINED"));
  MPI_STATUS_IGNORE = *((MPI_Status **)dlsym(handle, "mpi_STATUS_IGNORE"));

  err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(argc, argv);
}

int multimpi_MPI_File_write_all(MPI_File fh, void *buf, int count,
                                MPI_Datatype datatype, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_write_all");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype, status);
}

int multimpi_MPI_Scatterv(const void *sendbuf, const int *sendcounts,
                          const int *displs, MPI_Datatype sendtype,
                          void *recvbuf, int recvcount, MPI_Datatype recvtype,
                          int root, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, const int *, const int *, MPI_Datatype,
                      void *, int, MPI_Datatype, int, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Scatterv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
              recvtype, root, comm);
}

int multimpi_MPI_File_write_all_begin(MPI_File fh, void *buf, int count,
                                      MPI_Datatype datatype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype);
  wrap func = (wrap)dlsym(handle, "mpi_File_write_all_begin");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype);
}

int multimpi_MPI_Send(const void *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Send");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm);
}

int multimpi_MPI_File_write_all_end(MPI_File fh, void *buf,
                                    MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_write_all_end");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, status);
}

int multimpi_MPI_Send_init(const void *buf, int count, MPI_Datatype datatype,
                           int dest, int tag, MPI_Comm comm,
                           MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Send_init");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Abort(MPI_Comm comm, int errorcode) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int);
  wrap func = (wrap)dlsym(handle, "mpi_Abort");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, errorcode);
}

int multimpi_MPI_File_write_at(MPI_File fh, MPI_Offset offset, void *buf,
                               int count, MPI_Datatype datatype,
                               MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset, void *, int, MPI_Datatype,
                      MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_write_at");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset, buf, count, datatype, status);
}

int multimpi_MPI_Sendrecv(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, int dest, int sendtag,
                          void *recvbuf, int recvcount, MPI_Datatype recvtype,
                          int source, int recvtag, MPI_Comm comm,
                          MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, void *, int,
                      MPI_Datatype, int, int, MPI_Comm, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Sendrecv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount,
              recvtype, source, recvtag, comm, status);
}

int multimpi_MPI_Accumulate(const void *origin_addr, int origin_count,
                            MPI_Datatype origin_datatype, int target_rank,
                            MPI_Aint target_disp, int target_count,
                            MPI_Datatype target_datatype, MPI_Op op,
                            MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, MPI_Aint, int,
                      MPI_Datatype, MPI_Op, MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Accumulate");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(origin_addr, origin_count, origin_datatype, target_rank,
              target_disp, target_count, target_datatype, op, win);
}

int multimpi_MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, void *buf,
                                   int count, MPI_Datatype datatype,
                                   MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset, void *, int, MPI_Datatype,
                      MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_write_at_all");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset, buf, count, datatype, status);
}

int multimpi_MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype,
                                  int dest, int sendtag, int source,
                                  int recvtag, MPI_Comm comm,
                                  MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, int, MPI_Datatype, int, int, int, int, MPI_Comm,
                      MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Sendrecv_replace");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, sendtag, source, recvtag, comm,
              status);
}

int multimpi_MPI_Add_error_class(int *errorclass) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_Add_error_class");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(errorclass);
}

int multimpi_MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset,
                                         void *buf, int count,
                                         MPI_Datatype datatype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset, void *, int, MPI_Datatype);
  wrap func = (wrap)dlsym(handle, "mpi_File_write_at_all_begin");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset, buf, count, datatype);
}

int multimpi_MPI_Ssend(const void *buf, int count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Ssend");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm);
}

int multimpi_MPI_Add_error_code(int errorclass, int *errorcode) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Add_error_code");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(errorclass, errorcode);
}

int multimpi_MPI_File_write_at_all_end(MPI_File fh, void *buf,
                                       MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_write_at_all_end");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, status);
}

int multimpi_MPI_Ssend_init(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm,
                            MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ssend_init");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Add_error_string(int errorcode, const char *string) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, const char *);
  wrap func = (wrap)dlsym(handle, "mpi_Add_error_string");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(errorcode, string);
}

int multimpi_MPI_File_write_ordered(MPI_File fh, void *buf, int count,
                                    MPI_Datatype datatype, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_write_ordered");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype, status);
}

int multimpi_MPI_Start(MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Start");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(request);
}

int multimpi_MPI_Address(const void *location, MPI_Aint *address) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, MPI_Aint *);
  wrap func = (wrap)dlsym(handle, "mpi_Address");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(location, address);
}

int multimpi_MPI_File_write_ordered_begin(MPI_File fh, void *buf, int count,
                                          MPI_Datatype datatype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype);
  wrap func = (wrap)dlsym(handle, "mpi_File_write_ordered_begin");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype);
}

int multimpi_MPI_Startall(int count, MPI_Request array_of_requests[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Request[]);
  wrap func = (wrap)dlsym(handle, "mpi_Startall");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_requests);
}

int multimpi_MPI_Allgather(const void *sendbuf, int sendcount,
                           MPI_Datatype sendtype, void *recvbuf, int recvcount,
                           MPI_Datatype recvtype, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Allgather");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
}

int multimpi_MPI_File_write_ordered_end(MPI_File fh, void *buf,
                                        MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_write_ordered_end");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, status);
}

int multimpi_MPI_Status_set_cancelled(MPI_Status *status, int flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Status *, int);
  wrap func = (wrap)dlsym(handle, "mpi_Status_set_cancelled");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(status, flag);
}

int multimpi_MPI_Allgatherv(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            const int *recvcounts, const int *displs,
                            MPI_Datatype recvtype, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, const int *,
                      const int *, MPI_Datatype, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Allgatherv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
              recvtype, comm);
}

int multimpi_MPI_File_write_shared(MPI_File fh, void *buf, int count,
                                   MPI_Datatype datatype, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_write_shared");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype, status);
}

int multimpi_MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype,
                                     int count) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Status *, MPI_Datatype, int);
  wrap func = (wrap)dlsym(handle, "mpi_Status_set_elements");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(status, datatype, count);
}

int multimpi_MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Aint, MPI_Info, void *);
  wrap func = (wrap)dlsym(handle, "mpi_Alloc_mem");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(size, info, baseptr);
}

int multimpi_MPI_Finalize() {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)();
  wrap func = (wrap)dlsym(handle, "mpi_Finalize");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func();
}

int multimpi_MPI_Status_set_elements_x(MPI_Status *status,
                                       MPI_Datatype datatype, MPI_Count count) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Status *, MPI_Datatype, MPI_Count);
  wrap func = (wrap)dlsym(handle, "mpi_Status_set_elements_x");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(status, datatype, count);
}

int multimpi_MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,
                           MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, int, MPI_Datatype, MPI_Op,
                      MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Allreduce");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, count, datatype, op, comm);
}

int multimpi_MPI_Finalized(int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_Finalized");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(flag);
}

int multimpi_MPI_T_category_changed(int *stamp) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_T_category_changed");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(stamp);
}

int multimpi_MPI_Alltoall(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf, int recvcount,
                          MPI_Datatype recvtype, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Alltoall");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
}

int multimpi_MPI_Free_mem(void *base) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *);
  wrap func = (wrap)dlsym(handle, "mpi_Free_mem");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(base);
}

int multimpi_MPI_T_category_get_categories(int cat_index, int len,
                                           int indices[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, int[]);
  wrap func = (wrap)dlsym(handle, "mpi_T_category_get_categories");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(cat_index, len, indices);
}

int multimpi_MPI_Alltoallv(const void *sendbuf, const int *sendcounts,
                           const int *sdispls, MPI_Datatype sendtype,
                           void *recvbuf, const int *recvcounts,
                           const int *rdispls, MPI_Datatype recvtype,
                           MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, const int *, const int *, MPI_Datatype,
                      void *, const int *, const int *, MPI_Datatype, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Alltoallv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
              rdispls, recvtype, comm);
}

int multimpi_MPI_Gather(const void *sendbuf, int sendcount,
                        MPI_Datatype sendtype, void *recvbuf, int recvcount,
                        MPI_Datatype recvtype, int root, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, int, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Gather");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root,
              comm);
}

int multimpi_MPI_T_category_get_cvars(int cat_index, int len, int indices[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, int[]);
  wrap func = (wrap)dlsym(handle, "mpi_T_category_get_cvars");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(cat_index, len, indices);
}

int multimpi_MPI_Alltoallw(const void *sendbuf, const int sendcounts[],
                           const int sdispls[], const MPI_Datatype sendtypes[],
                           void *recvbuf, const int recvcounts[],
                           const int rdispls[], const MPI_Datatype recvtypes[],
                           MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, const int[], const int[],
                      const MPI_Datatype[], void *, const int[], const int[],
                      const MPI_Datatype[], MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Alltoallw");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts,
              rdispls, recvtypes, comm);
}

int multimpi_MPI_Gatherv(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, void *recvbuf,
                         const int *recvcounts, const int *displs,
                         MPI_Datatype recvtype, int root, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, const int *,
                      const int *, MPI_Datatype, int, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Gatherv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
              recvtype, root, comm);
}

int multimpi_MPI_T_category_get_info(int cat_index, char *name, int *name_len,
                                     char *desc, int *desc_len, int *num_cvars,
                                     int *num_pvars, int *num_categories) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, char *, int *, char *, int *, int *, int *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_T_category_get_info");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars,
              num_categories);
}

int multimpi_MPI_Attr_delete(MPI_Comm comm, int keyval) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int);
  wrap func = (wrap)dlsym(handle, "mpi_Attr_delete");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, keyval);
}

int multimpi_MPI_Get(void *origin_addr, int origin_count,
                     MPI_Datatype origin_datatype, int target_rank,
                     MPI_Aint target_disp, int target_count,
                     MPI_Datatype target_datatype, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, int, MPI_Datatype, int, MPI_Aint, int,
                      MPI_Datatype, MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Get");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(origin_addr, origin_count, origin_datatype, target_rank,
              target_disp, target_count, target_datatype, win);
}

int multimpi_MPI_T_category_get_num(int *num_cat) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_T_category_get_num");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(num_cat);
}

int multimpi_MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val,
                          int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, void *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Attr_get");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, keyval, attribute_val, flag);
}

int multimpi_MPI_Get_accumulate(const void *origin_addr, int origin_count,
                                MPI_Datatype origin_datatype, void *result_addr,
                                int result_count, MPI_Datatype result_datatype,
                                int target_rank, MPI_Aint target_disp,
                                int target_count, MPI_Datatype target_datatype,
                                MPI_Op op, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op,
                      MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Get_accumulate");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(origin_addr, origin_count, origin_datatype, result_addr,
              result_count, result_datatype, target_rank, target_disp,
              target_count, target_datatype, op, win);
}

int multimpi_MPI_T_category_get_pvars(int cat_index, int len, int indices[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, int[]);
  wrap func = (wrap)dlsym(handle, "mpi_T_category_get_pvars");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(cat_index, len, indices);
}

int multimpi_MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, void *);
  wrap func = (wrap)dlsym(handle, "mpi_Attr_put");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, keyval, attribute_val);
}

int multimpi_MPI_Get_address(const void *location, MPI_Aint *address) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, MPI_Aint *);
  wrap func = (wrap)dlsym(handle, "mpi_Get_address");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(location, address);
}

int multimpi_MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                                 int *verbosity, MPI_Datatype *datatype,
                                 MPI_T_enum *enumtype, char *desc,
                                 int *desc_len, int *binding, int *scope) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, char *, int *, int *, MPI_Datatype *, MPI_T_enum *,
                      char *, int *, int *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_T_cvar_get_info");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(cvar_index, name, name_len, verbosity, datatype, enumtype, desc,
              desc_len, binding, scope);
}

int multimpi_MPI_Barrier(MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Barrier");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm);
}

int multimpi_MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype,
                           int *count) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const MPI_Status *, MPI_Datatype, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Get_count");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(status, datatype, count);
}

int multimpi_MPI_T_cvar_get_num(int *num_cvar) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_T_cvar_get_num");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(num_cvar);
}

int multimpi_MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root,
                       MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, int, MPI_Datatype, int, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Bcast");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buffer, count, datatype, root, comm);
}

int multimpi_MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype,
                              int *count) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const MPI_Status *, MPI_Datatype, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Get_elements");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(status, datatype, count);
}

int multimpi_MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                                     MPI_T_cvar_handle *handle, int *count) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, void *, MPI_T_cvar_handle *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_T_cvar_handle_alloc");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(cvar_index, obj_handle, handle, count);
}

int multimpi_MPI_Bsend(const void *buf, int count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Bsend");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm);
}

int multimpi_MPI_Get_elements_x(const MPI_Status *status, MPI_Datatype datatype,
                                MPI_Count *count) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const MPI_Status *, MPI_Datatype, MPI_Count *);
  wrap func = (wrap)dlsym(handle, "mpi_Get_elements_x");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(status, datatype, count);
}

int multimpi_MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_cvar_handle *);
  wrap func = (wrap)dlsym(handle, "mpi_T_cvar_handle_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(handle);
}

int multimpi_MPI_Bsend_init(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm,
                            MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Bsend_init");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Get_library_version(char *version, int *resultlen) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(char *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Get_library_version");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(version, resultlen);
}

int multimpi_MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_cvar_handle, void *);
  wrap func = (wrap)dlsym(handle, "mpi_T_cvar_read");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(handle, buf);
}

int multimpi_MPI_Buffer_attach(void *buffer, int size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, int);
  wrap func = (wrap)dlsym(handle, "mpi_Buffer_attach");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buffer, size);
}

int multimpi_MPI_Get_processor_name(char *name, int *resultlen) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(char *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Get_processor_name");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(name, resultlen);
}

int multimpi_MPI_T_cvar_write(MPI_T_cvar_handle handle, void *buf) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_cvar_handle, void *);
  wrap func = (wrap)dlsym(handle, "mpi_T_cvar_write");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(handle, buf);
}

int multimpi_MPI_Buffer_detach(void *buffer_addr, int *size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Buffer_detach");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buffer_addr, size);
}

int multimpi_MPI_Get_version(int *version, int *subversion) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Get_version");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(version, subversion);
}

int multimpi_MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name,
                                 int *name_len) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_enum, int *, char *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_T_enum_get_info");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(enumtype, num, name, name_len);
}

int multimpi_MPI_Cancel(MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Cancel");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(request);
}

int multimpi_MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int indx[],
                              const int edges[], int reorder,
                              MPI_Comm *comm_graph) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, const int[], const int[], int, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Graph_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm_old, nnodes, indx, edges, reorder, comm_graph);
}

int multimpi_MPI_T_enum_get_item(MPI_T_enum enumtype, int index, int *value,
                                 char *name, int *name_len) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_enum, int, int *, char *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_T_enum_get_item");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(enumtype, index, value, name, name_len);
}

int multimpi_MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims,
                             int coords[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, int, int[]);
  wrap func = (wrap)dlsym(handle, "mpi_Cart_coords");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, rank, maxdims, coords);
}

int multimpi_MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges,
                           int indx[], int edges[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, int, int[], int[]);
  wrap func = (wrap)dlsym(handle, "mpi_Graph_get");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, maxindex, maxedges, indx, edges);
}

int multimpi_MPI_T_finalize() {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)();
  wrap func = (wrap)dlsym(handle, "mpi_T_finalize");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func();
}

int multimpi_MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[],
                             const int periods[], int reorder,
                             MPI_Comm *comm_cart) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, const int[], const int[], int, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Cart_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm_old, ndims, dims, periods, reorder, comm_cart);
}

int multimpi_MPI_Graph_map(MPI_Comm comm, int nnodes, const int indx[],
                           const int edges[], int *newrank) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, const int[], const int[], int *);
  wrap func = (wrap)dlsym(handle, "mpi_Graph_map");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, nnodes, indx, edges, newrank);
}

int multimpi_MPI_T_init_thread(int required, int *provided) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int *);
  wrap func = (wrap)dlsym(handle, "mpi_T_init_thread");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(required, provided);
}

int multimpi_MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[],
                          int coords[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, int[], int[], int[]);
  wrap func = (wrap)dlsym(handle, "mpi_Cart_get");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, maxdims, dims, periods, coords);
}

int multimpi_MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors,
                                 int neighbors[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, int, int[]);
  wrap func = (wrap)dlsym(handle, "mpi_Graph_neighbors");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, rank, maxneighbors, neighbors);
}

int multimpi_MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                                 int *verbosity, int *var_class,
                                 MPI_Datatype *datatype, MPI_T_enum *enumtype,
                                 char *desc, int *desc_len, int *binding,
                                 int *readonly, int *continuous, int *atomic) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, char *, int *, int *, int *, MPI_Datatype *,
                      MPI_T_enum *, char *, int *, int *, int *, int *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_T_pvar_get_info");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(pvar_index, name, name_len, verbosity, var_class, datatype,
              enumtype, desc, desc_len, binding, readonly, continuous, atomic);
}

int multimpi_MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[],
                          const int periods[], int *newrank) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, const int[], const int[], int *);
  wrap func = (wrap)dlsym(handle, "mpi_Cart_map");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, ndims, dims, periods, newrank);
}

int multimpi_MPI_Graph_neighbors_count(MPI_Comm comm, int rank,
                                       int *nneighbors) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Graph_neighbors_count");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, rank, nneighbors);
}

int multimpi_MPI_T_pvar_get_num(int *num_pvar) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_T_pvar_get_num");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(num_pvar);
}

int multimpi_MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, const int[], int *);
  wrap func = (wrap)dlsym(handle, "mpi_Cart_rank");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, coords, rank);
}

int multimpi_MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Graphdims_get");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, nnodes, nedges);
}

int multimpi_MPI_T_pvar_handle_alloc(MPI_T_pvar_session session, int pvar_index,
                                     void *obj_handle,
                                     MPI_T_pvar_handle *handle, int *count) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_pvar_session, int, void *, MPI_T_pvar_handle *,
                      int *);
  wrap func = (wrap)dlsym(handle, "mpi_T_pvar_handle_alloc");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(session, pvar_index, obj_handle, handle, count);
}

int multimpi_MPI_Cart_shift(MPI_Comm comm, int direction, int disp,
                            int *rank_source, int *rank_dest) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, int, int *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Cart_shift");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, direction, disp, rank_source, rank_dest);
}

int multimpi_MPI_Grequest_complete(MPI_Request request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Request);
  wrap func = (wrap)dlsym(handle, "mpi_Grequest_complete");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(request);
}

int multimpi_MPI_T_pvar_handle_free(MPI_T_pvar_session session,
                                    MPI_T_pvar_handle *handle) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_pvar_session, MPI_T_pvar_handle *);
  wrap func = (wrap)dlsym(handle, "mpi_T_pvar_handle_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(session, handle);
}

int multimpi_MPI_Cart_sub(MPI_Comm comm, const int remain_dims[],
                          MPI_Comm *newcomm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, const int[], MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Cart_sub");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, remain_dims, newcomm);
}

int multimpi_MPI_Grequest_start(MPI_Grequest_query_function *query_fn,
                                MPI_Grequest_free_function *free_fn,
                                MPI_Grequest_cancel_function *cancel_fn,
                                void *extra_state, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Grequest_query_function *,
                      MPI_Grequest_free_function *,
                      MPI_Grequest_cancel_function *, void *, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Grequest_start");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(query_fn, free_fn, cancel_fn, extra_state, request);
}

int multimpi_MPI_T_pvar_read(MPI_T_pvar_session session,
                             MPI_T_pvar_handle handle, void *buf) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_pvar_session, MPI_T_pvar_handle, void *);
  wrap func = (wrap)dlsym(handle, "mpi_T_pvar_read");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(session, handle, buf);
}

int multimpi_MPI_Cartdim_get(MPI_Comm comm, int *ndims) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Cartdim_get");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, ndims);
}

int multimpi_MPI_Group_compare(MPI_Group group1, MPI_Group group2,
                               int *result) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, MPI_Group, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Group_compare");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group1, group2, result);
}

int multimpi_MPI_T_pvar_readreset(MPI_T_pvar_session session,
                                  MPI_T_pvar_handle handle, void *buf) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_pvar_session, MPI_T_pvar_handle, void *);
  wrap func = (wrap)dlsym(handle, "mpi_T_pvar_readreset");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(session, handle, buf);
}

int multimpi_MPI_Close_port(const char *port_name) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const char *);
  wrap func = (wrap)dlsym(handle, "mpi_Close_port");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(port_name);
}

int multimpi_MPI_Group_difference(MPI_Group group1, MPI_Group group2,
                                  MPI_Group *newgroup) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, MPI_Group, MPI_Group *);
  wrap func = (wrap)dlsym(handle, "mpi_Group_difference");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group1, group2, newgroup);
}

int multimpi_MPI_T_pvar_reset(MPI_T_pvar_session session,
                              MPI_T_pvar_handle handle) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_pvar_session, MPI_T_pvar_handle);
  wrap func = (wrap)dlsym(handle, "mpi_T_pvar_reset");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(session, handle);
}

int multimpi_MPI_Comm_accept(const char *port_name, MPI_Info info, int root,
                             MPI_Comm comm, MPI_Comm *newcomm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const char *, MPI_Info, int, MPI_Comm, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_accept");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(port_name, info, root, comm, newcomm);
}

int multimpi_MPI_Group_excl(MPI_Group group, int n, const int ranks[],
                            MPI_Group *newgroup) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, int, const int[], MPI_Group *);
  wrap func = (wrap)dlsym(handle, "mpi_Group_excl");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group, n, ranks, newgroup);
}

int multimpi_MPI_T_pvar_session_create(MPI_T_pvar_session *session) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_pvar_session *);
  wrap func = (wrap)dlsym(handle, "mpi_T_pvar_session_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(session);
}

int multimpi_MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_call_errhandler");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, errorcode);
}

int multimpi_MPI_Group_free(MPI_Group *group) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group *);
  wrap func = (wrap)dlsym(handle, "mpi_Group_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group);
}

int multimpi_MPI_T_pvar_session_free(MPI_T_pvar_session *session) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_pvar_session *);
  wrap func = (wrap)dlsym(handle, "mpi_T_pvar_session_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(session);
}

int multimpi_MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Comm, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_compare");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm1, comm2, result);
}

int multimpi_MPI_Group_incl(MPI_Group group, int n, const int ranks[],
                            MPI_Group *newgroup) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, int, const int[], MPI_Group *);
  wrap func = (wrap)dlsym(handle, "mpi_Group_incl");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group, n, ranks, newgroup);
}

int multimpi_MPI_T_pvar_start(MPI_T_pvar_session session,
                              MPI_T_pvar_handle handle) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_pvar_session, MPI_T_pvar_handle);
  wrap func = (wrap)dlsym(handle, "mpi_T_pvar_start");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(session, handle);
}

int multimpi_MPI_Comm_connect(const char *port_name, MPI_Info info, int root,
                              MPI_Comm comm, MPI_Comm *newcomm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const char *, MPI_Info, int, MPI_Comm, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_connect");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(port_name, info, root, comm, newcomm);
}

int multimpi_MPI_Group_intersection(MPI_Group group1, MPI_Group group2,
                                    MPI_Group *newgroup) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, MPI_Group, MPI_Group *);
  wrap func = (wrap)dlsym(handle, "mpi_Group_intersection");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group1, group2, newgroup);
}

int multimpi_MPI_T_pvar_stop(MPI_T_pvar_session session,
                             MPI_T_pvar_handle handle) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_pvar_session, MPI_T_pvar_handle);
  wrap func = (wrap)dlsym(handle, "mpi_T_pvar_stop");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(session, handle);
}

int multimpi_MPI_Comm_create(MPI_Comm comm, MPI_Group group,
                             MPI_Comm *newcomm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Group, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, group, newcomm);
}

int multimpi_MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
                                  MPI_Group *newgroup) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, int, int[][3], MPI_Group *);
  wrap func = (wrap)dlsym(handle, "mpi_Group_range_excl");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group, n, ranges, newgroup);
}

int multimpi_MPI_T_pvar_write(MPI_T_pvar_session session,
                              MPI_T_pvar_handle handle, void *buf) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_T_pvar_session, MPI_T_pvar_handle, void *);
  wrap func = (wrap)dlsym(handle, "mpi_T_pvar_write");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(session, handle, buf);
}

int multimpi_MPI_Comm_create_errhandler(
    MPI_Comm_errhandler_function *comm_errhandler_fn,
    MPI_Errhandler *errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm_errhandler_function *, MPI_Errhandler *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_create_errhandler");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm_errhandler_fn, errhandler);
}

int multimpi_MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3],
                                  MPI_Group *newgroup) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, int, int[][3], MPI_Group *);
  wrap func = (wrap)dlsym(handle, "mpi_Group_range_incl");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group, n, ranges, newgroup);
}

int multimpi_MPI_Test(MPI_Request *request, int *flag, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Request *, int *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Test");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(request, flag, status);
}

int multimpi_MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag,
                                   MPI_Comm *newcomm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Group, int, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_create_group");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, group, tag, newcomm);
}

int multimpi_MPI_Group_rank(MPI_Group group, int *rank) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Group_rank");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group, rank);
}

int multimpi_MPI_Test_cancelled(const MPI_Status *status, int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const MPI_Status *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Test_cancelled");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(status, flag);
}

int multimpi_MPI_Comm_create_keyval(
    MPI_Comm_copy_attr_function *comm_copy_attr_fn,
    MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
    void *extra_state) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm_copy_attr_function *,
                      MPI_Comm_delete_attr_function *, int *, void *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_create_keyval");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);
}

int multimpi_MPI_Group_size(MPI_Group group, int *size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Group_size");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group, size);
}

int multimpi_MPI_Testall(int count, MPI_Request array_of_requests[], int *flag,
                         MPI_Status array_of_statuses[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Request[], int *, MPI_Status[]);
  wrap func = (wrap)dlsym(handle, "mpi_Testall");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_requests, flag, array_of_statuses);
}

int multimpi_MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_delete_attr");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, comm_keyval);
}

int multimpi_MPI_Group_translate_ranks(MPI_Group group1, int n,
                                       const int ranks1[], MPI_Group group2,
                                       int ranks2[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, int, const int[], MPI_Group, int[]);
  wrap func = (wrap)dlsym(handle, "mpi_Group_translate_ranks");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group1, n, ranks1, group2, ranks2);
}

int multimpi_MPI_Testany(int count, MPI_Request array_of_requests[], int *indx,
                         int *flag, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Request[], int *, int *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Testany");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_requests, indx, flag, status);
}

int multimpi_MPI_Comm_disconnect(MPI_Comm *comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_disconnect");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm);
}

int multimpi_MPI_Group_union(MPI_Group group1, MPI_Group group2,
                             MPI_Group *newgroup) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, MPI_Group, MPI_Group *);
  wrap func = (wrap)dlsym(handle, "mpi_Group_union");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group1, group2, newgroup);
}

int multimpi_MPI_Testsome(int incount, MPI_Request array_of_requests[],
                          int *outcount, int array_of_indices[],
                          MPI_Status array_of_statuses[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Request[], int *, int[], MPI_Status[]);
  wrap func = (wrap)dlsym(handle, "mpi_Testsome");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(incount, array_of_requests, outcount, array_of_indices,
              array_of_statuses);
}

int multimpi_MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_dup");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, newcomm);
}

int multimpi_MPI_Iallgather(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf, int recvcount,
                            MPI_Datatype recvtype, MPI_Comm comm,
                            MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Iallgather");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm,
              request);
}

int multimpi_MPI_Topo_test(MPI_Comm comm, int *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Topo_test");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, status);
}

int multimpi_MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info,
                                    MPI_Comm *newcomm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Info, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_dup_with_info");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, info, newcomm);
}

int multimpi_MPI_Iallgatherv(const void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             const int recvcounts[], const int displs[],
                             MPI_Datatype recvtype, MPI_Comm comm,
                             MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, const int[],
                      const int[], MPI_Datatype, MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Iallgatherv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
              recvtype, comm, request);
}

int multimpi_MPI_Type_commit(MPI_Datatype *datatype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_commit");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype);
}

int multimpi_MPI_Comm_free(MPI_Comm *comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm);
}

int multimpi_MPI_Iallreduce(const void *sendbuf, void *recvbuf, int count,
                            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                            MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Iallreduce");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, count, datatype, op, comm, request);
}

int multimpi_MPI_Type_contiguous(int count, MPI_Datatype oldtype,
                                 MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Datatype, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_contiguous");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, oldtype, newtype);
}

int multimpi_MPI_Comm_free_keyval(int *comm_keyval) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_free_keyval");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm_keyval);
}

int multimpi_MPI_Ialltoall(const void *sendbuf, int sendcount,
                           MPI_Datatype sendtype, void *recvbuf, int recvcount,
                           MPI_Datatype recvtype, MPI_Comm comm,
                           MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ialltoall");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm,
              request);
}

int multimpi_MPI_Type_create_darray(int size, int rank, int ndims,
                                    const int array_of_gsizes[],
                                    const int array_of_distribs[],
                                    const int array_of_dargs[],
                                    const int array_of_psizes[], int order,
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, int, const int[], const int[], const int[],
                      const int[], int, MPI_Datatype, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_create_darray");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(size, rank, ndims, array_of_gsizes, array_of_distribs,
              array_of_dargs, array_of_psizes, order, oldtype, newtype);
}

int multimpi_MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval,
                               void *attribute_val, int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, void *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_get_attr");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, comm_keyval, attribute_val, flag);
}

int multimpi_MPI_Ialltoallv(const void *sendbuf, const int sendcounts[],
                            const int sdispls[], MPI_Datatype sendtype,
                            void *recvbuf, const int recvcounts[],
                            const int rdispls[], MPI_Datatype recvtype,
                            MPI_Comm comm, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, const int[], const int[], MPI_Datatype,
                      void *, const int[], const int[], MPI_Datatype, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ialltoallv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
              rdispls, recvtype, comm, request);
}

int multimpi_MPI_Type_create_f90_complex(int precision, int range,
                                         MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_create_f90_complex");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(precision, range, newtype);
}

int multimpi_MPI_Comm_get_errhandler(MPI_Comm comm,
                                     MPI_Errhandler *errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Errhandler *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_get_errhandler");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, errhandler);
}

int multimpi_MPI_Ialltoallw(const void *sendbuf, const int sendcounts[],
                            const int sdispls[], const MPI_Datatype sendtypes[],
                            void *recvbuf, const int recvcounts[],
                            const int rdispls[], const MPI_Datatype recvtypes[],
                            MPI_Comm comm, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, const int[], const int[],
                      const MPI_Datatype[], void *, const int[], const int[],
                      const MPI_Datatype[], MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ialltoallw");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts,
              rdispls, recvtypes, comm, request);
}

int multimpi_MPI_Type_create_f90_integer(int range, MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_create_f90_integer");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(range, newtype);
}

int multimpi_MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Info *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_get_info");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, info_used);
}

int multimpi_MPI_Ibarrier(MPI_Comm comm, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ibarrier");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, request);
}

int multimpi_MPI_Type_create_f90_real(int precision, int range,
                                      MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_create_f90_real");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(precision, range, newtype);
}

int multimpi_MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, char *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_get_name");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, comm_name, resultlen);
}

int multimpi_MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype,
                        int root, MPI_Comm comm, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ibcast");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buffer, count, datatype, root, comm, request);
}

int multimpi_MPI_Type_create_hindexed(int count,
                                      const int array_of_blocklengths[],
                                      const MPI_Aint array_of_displacements[],
                                      MPI_Datatype oldtype,
                                      MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, const int[], const MPI_Aint[], MPI_Datatype,
                      MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_create_hindexed");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_blocklengths, array_of_displacements, oldtype,
              newtype);
}

int multimpi_MPI_Comm_get_parent(MPI_Comm *parent) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_get_parent");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(parent);
}

int multimpi_MPI_Ibsend(const void *buf, int count, MPI_Datatype datatype,
                        int dest, int tag, MPI_Comm comm,
                        MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ibsend");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Type_create_hindexed_block(
    int count, int blocklength, const MPI_Aint array_of_displacements[],
    MPI_Datatype oldtype, MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, const MPI_Aint[], MPI_Datatype, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_create_hindexed_block");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, blocklength, array_of_displacements, oldtype, newtype);
}

int multimpi_MPI_Comm_group(MPI_Comm comm, MPI_Group *group) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Group *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_group");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, group);
}

int multimpi_MPI_Iexscan(const void *sendbuf, void *recvbuf, int count,
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                         MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Iexscan");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, count, datatype, op, comm, request);
}

int multimpi_MPI_Type_create_hvector(int count, int blocklength,
                                     MPI_Aint stride, MPI_Datatype oldtype,
                                     MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_create_hvector");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, blocklength, stride, oldtype, newtype);
}

int multimpi_MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm,
                           MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Comm *, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_idup");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, newcomm, request);
}

int multimpi_MPI_Igather(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, void *recvbuf, int recvcount,
                         MPI_Datatype recvtype, int root, MPI_Comm comm,
                         MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, int, MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Igather");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root,
              comm, request);
}

int multimpi_MPI_Type_create_indexed_block(int count, int blocklength,
                                           const int array_of_displacements[],
                                           MPI_Datatype oldtype,
                                           MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, const int[], MPI_Datatype, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_create_indexed_block");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, blocklength, array_of_displacements, oldtype, newtype);
}

int multimpi_MPI_Comm_join(int fd, MPI_Comm *intercomm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_join");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fd, intercomm);
}

int multimpi_MPI_Igatherv(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          const int recvcounts[], const int displs[],
                          MPI_Datatype recvtype, int root, MPI_Comm comm,
                          MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, const int[],
                      const int[], MPI_Datatype, int, MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Igatherv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
              recvtype, root, comm, request);
}

int multimpi_MPI_Type_create_keyval(
    MPI_Type_copy_attr_function *type_copy_attr_fn,
    MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval,
    void *extra_state) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Type_copy_attr_function *,
                      MPI_Type_delete_attr_function *, int *, void *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_create_keyval");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state);
}

int multimpi_MPI_Comm_rank(MPI_Comm comm, int *rank) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_rank");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, rank);
}

int multimpi_MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag,
                         MPI_Message *message, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, MPI_Comm, int *, MPI_Message *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Improbe");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(source, tag, comm, flag, message, status);
}

int multimpi_MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb,
                                     MPI_Aint extent, MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, MPI_Aint, MPI_Aint, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_create_resized");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(oldtype, lb, extent, newtype);
}

int multimpi_MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Group *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_remote_group");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, group);
}

int multimpi_MPI_Imrecv(void *buf, int count, MPI_Datatype datatype,
                        MPI_Message *message, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, int, MPI_Datatype, MPI_Message *, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Imrecv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, message, request);
}

int multimpi_MPI_Type_create_struct(int count,
                                    const int array_of_blocklengths[],
                                    const MPI_Aint array_of_displacements[],
                                    const MPI_Datatype array_of_types[],
                                    MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, const int[], const MPI_Aint[], const MPI_Datatype[],
                      MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_create_struct");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_blocklengths, array_of_displacements,
              array_of_types, newtype);
}

int multimpi_MPI_Comm_remote_size(MPI_Comm comm, int *size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_remote_size");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, size);
}

int multimpi_MPI_Ineighbor_allgather(const void *sendbuf, int sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     int recvcount, MPI_Datatype recvtype,
                                     MPI_Comm comm, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ineighbor_allgather");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm,
              request);
}

int multimpi_MPI_Type_create_subarray(int ndims, const int array_of_sizes[],
                                      const int array_of_subsizes[],
                                      const int array_of_starts[], int order,
                                      MPI_Datatype oldtype,
                                      MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, const int[], const int[], const int[], int,
                      MPI_Datatype, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_create_subarray");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order,
              oldtype, newtype);
}

int multimpi_MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval,
                               void *attribute_val) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, void *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_set_attr");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, comm_keyval, attribute_val);
}

int multimpi_MPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      const int recvcounts[],
                                      const int displs[], MPI_Datatype recvtype,
                                      MPI_Comm comm, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, const int[],
                      const int[], MPI_Datatype, MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ineighbor_allgatherv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
              recvtype, comm, request);
}

int multimpi_MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, int);
  wrap func = (wrap)dlsym(handle, "mpi_Type_delete_attr");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, type_keyval);
}

int multimpi_MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Errhandler);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_set_errhandler");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, errhandler);
}

int multimpi_MPI_Ineighbor_alltoall(const void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    int recvcount, MPI_Datatype recvtype,
                                    MPI_Comm comm, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ineighbor_alltoall");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm,
              request);
}

int multimpi_MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_dup");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(oldtype, newtype);
}

int multimpi_MPI_Comm_set_info(MPI_Comm comm, MPI_Info info) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Info);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_set_info");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, info);
}

int multimpi_MPI_Ineighbor_alltoallv(const void *sendbuf,
                                     const int sendcounts[],
                                     const int sdispls[], MPI_Datatype sendtype,
                                     void *recvbuf, const int recvcounts[],
                                     const int rdispls[], MPI_Datatype recvtype,
                                     MPI_Comm comm, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, const int[], const int[], MPI_Datatype,
                      void *, const int[], const int[], MPI_Datatype, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ineighbor_alltoallv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
              rdispls, recvtype, comm, request);
}

int multimpi_MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, MPI_Aint *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_extent");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, extent);
}

int multimpi_MPI_Comm_set_name(MPI_Comm comm, const char *comm_name) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, const char *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_set_name");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, comm_name);
}

int multimpi_MPI_Ineighbor_alltoallw(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, const int[], const MPI_Aint[],
                      const MPI_Datatype[], void *, const int[],
                      const MPI_Aint[], const MPI_Datatype[], MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ineighbor_alltoallw");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts,
              rdispls, recvtypes, comm, request);
}

int multimpi_MPI_Type_free(MPI_Datatype *datatype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype);
}

int multimpi_MPI_Comm_size(MPI_Comm comm, int *size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_size");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, size);
}

int multimpi_MPI_Info_create(MPI_Info *info) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Info *);
  wrap func = (wrap)dlsym(handle, "mpi_Info_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(info);
}

int multimpi_MPI_Type_free_keyval(int *type_keyval) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_free_keyval");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(type_keyval);
}

int multimpi_MPI_Comm_spawn(const char *command, char *argv[], int maxprocs,
                            MPI_Info info, int root, MPI_Comm comm,
                            MPI_Comm *intercomm, int array_of_errcodes[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const char *, char *[], int, MPI_Info, int, MPI_Comm,
                      MPI_Comm *, int[]);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_spawn");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(command, argv, maxprocs, info, root, comm, intercomm,
              array_of_errcodes);
}

int multimpi_MPI_Info_delete(MPI_Info info, const char *key) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Info, const char *);
  wrap func = (wrap)dlsym(handle, "mpi_Info_delete");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(info, key);
}

int multimpi_MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval,
                               void *attribute_val, int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, int, void *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_get_attr");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, type_keyval, attribute_val, flag);
}

int multimpi_MPI_Comm_spawn_multiple(int count, char *array_of_commands[],
                                     char **array_of_argv[],
                                     const int array_of_maxprocs[],
                                     const MPI_Info array_of_info[], int root,
                                     MPI_Comm comm, MPI_Comm *intercomm,
                                     int array_of_errcodes[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, char *[], char **[], const int[], const MPI_Info[],
                      int, MPI_Comm, MPI_Comm *, int[]);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_spawn_multiple");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_commands, array_of_argv, array_of_maxprocs,
              array_of_info, root, comm, intercomm, array_of_errcodes);
}

int multimpi_MPI_Info_dup(MPI_Info info, MPI_Info *newinfo) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Info, MPI_Info *);
  wrap func = (wrap)dlsym(handle, "mpi_Info_dup");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(info, newinfo);
}

int multimpi_MPI_Type_get_contents(MPI_Datatype datatype, int max_integers,
                                   int max_addresses, int max_datatypes,
                                   int array_of_integers[],
                                   MPI_Aint array_of_addresses[],
                                   MPI_Datatype array_of_datatypes[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, int, int, int, int[], MPI_Aint[],
                      MPI_Datatype[]);
  wrap func = (wrap)dlsym(handle, "mpi_Type_get_contents");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, max_integers, max_addresses, max_datatypes,
              array_of_integers, array_of_addresses, array_of_datatypes);
}

int multimpi_MPI_Comm_split(MPI_Comm comm, int color, int key,
                            MPI_Comm *newcomm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, int, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_split");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, color, key, newcomm);
}

int multimpi_MPI_Info_free(MPI_Info *info) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Info *);
  wrap func = (wrap)dlsym(handle, "mpi_Info_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(info);
}

int multimpi_MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers,
                                   int *num_addresses, int *num_datatypes,
                                   int *combiner) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, int *, int *, int *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_get_envelope");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, num_integers, num_addresses, num_datatypes, combiner);
}

int multimpi_MPI_Comm_split_type(MPI_Comm comm, int split_type, int key,
                                 MPI_Info info, MPI_Comm *newcomm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, int, MPI_Info, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_split_type");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, split_type, key, info, newcomm);
}

int multimpi_MPI_Info_get(MPI_Info info, const char *key, int valuelen,
                          char *value, int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Info, const char *, int, char *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Info_get");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(info, key, valuelen, value, flag);
}

int multimpi_MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb,
                                 MPI_Aint *extent) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, MPI_Aint *, MPI_Aint *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_get_extent");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, lb, extent);
}

int multimpi_MPI_Comm_test_inter(MPI_Comm comm, int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_test_inter");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, flag);
}

int multimpi_MPI_Info_get_nkeys(MPI_Info info, int *nkeys) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Info, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Info_get_nkeys");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(info, nkeys);
}

int multimpi_MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                                   MPI_Count *extent) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, MPI_Count *, MPI_Count *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_get_extent_x");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, lb, extent);
}

int multimpi_MPI_Compare_and_swap(const void *origin_addr,
                                  const void *compare_addr, void *result_addr,
                                  MPI_Datatype datatype, int target_rank,
                                  MPI_Aint target_disp, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, const void *, void *, MPI_Datatype, int,
                      MPI_Aint, MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Compare_and_swap");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(origin_addr, compare_addr, result_addr, datatype, target_rank,
              target_disp, win);
}

int multimpi_MPI_Info_get_nthkey(MPI_Info info, int n, char *key) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Info, int, char *);
  wrap func = (wrap)dlsym(handle, "mpi_Info_get_nthkey");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(info, n, key);
}

int multimpi_MPI_Type_get_name(MPI_Datatype datatype, char *type_name,
                               int *resultlen) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, char *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_get_name");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, type_name, resultlen);
}

int multimpi_MPI_Dims_create(int nnodes, int ndims, int dims[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, int[]);
  wrap func = (wrap)dlsym(handle, "mpi_Dims_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(nnodes, ndims, dims);
}

int multimpi_MPI_Info_get_valuelen(MPI_Info info, const char *key,
                                   int *valuelen, int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Info, const char *, int *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Info_get_valuelen");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(info, key, valuelen, flag);
}

int multimpi_MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb,
                                      MPI_Aint *true_extent) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, MPI_Aint *, MPI_Aint *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_get_true_extent");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, true_lb, true_extent);
}

int multimpi_MPI_Dist_graph_create(MPI_Comm comm_old, int n,
                                   const int sources[], const int degrees[],
                                   const int destinations[],
                                   const int weights[], MPI_Info info,
                                   int reorder, MPI_Comm *comm_dist_graph) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, const int[], const int[], const int[],
                      const int[], MPI_Info, int, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Dist_graph_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm_old, n, sources, degrees, destinations, weights, info,
              reorder, comm_dist_graph);
}

int multimpi_MPI_Info_set(MPI_Info info, const char *key, const char *value) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Info, const char *, const char *);
  wrap func = (wrap)dlsym(handle, "mpi_Info_set");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(info, key, value);
}

int multimpi_MPI_Type_get_true_extent_x(MPI_Datatype datatype,
                                        MPI_Count *true_lb,
                                        MPI_Count *true_extent) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, MPI_Count *, MPI_Count *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_get_true_extent_x");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, true_lb, true_extent);
}

int multimpi_MPI_Dist_graph_create_adjacent(
    MPI_Comm comm_old, int indegree, const int sources[],
    const int sourceweights[], int outdegree, const int destinations[],
    const int destweights[], MPI_Info info, int reorder,
    MPI_Comm *comm_dist_graph) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, const int[], const int[], int, const int[],
                      const int[], MPI_Info, int, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Dist_graph_create_adjacent");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm_old, indegree, sources, sourceweights, outdegree,
              destinations, destweights, info, reorder, comm_dist_graph);
}

int multimpi_MPI_Type_hindexed(int count, const int *array_of_blocklengths,
                               const MPI_Aint *array_of_displacements,
                               MPI_Datatype oldtype, MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, const int *, const MPI_Aint *, MPI_Datatype,
                      MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_hindexed");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_blocklengths, array_of_displacements, oldtype,
              newtype);
}

int multimpi_MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree,
                                      int sources[], int sourceweights[],
                                      int maxoutdegree, int destinations[],
                                      int destweights[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, int[], int[], int, int[], int[]);
  wrap func = (wrap)dlsym(handle, "mpi_Dist_graph_neighbors");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, maxindegree, sources, sourceweights, maxoutdegree,
              destinations, destweights);
}

int multimpi_MPI_Init_thread(int *argc, char ***argv, int required,
                             int *provided) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *, char ***, int, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Init_thread");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(argc, argv, required, provided);
}

int multimpi_MPI_Type_hvector(int count, int blocklength, MPI_Aint stride,
                              MPI_Datatype oldtype, MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_hvector");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, blocklength, stride, oldtype, newtype);
}

int multimpi_MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree,
                                            int *outdegree, int *weighted) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int *, int *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Dist_graph_neighbors_count");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, indegree, outdegree, weighted);
}

int multimpi_MPI_Initialized(int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_Initialized");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(flag);
}

int multimpi_MPI_Type_indexed(int count, const int *array_of_blocklengths,
                              const int *array_of_displacements,
                              MPI_Datatype oldtype, MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, const int *, const int *, MPI_Datatype,
                      MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_indexed");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_blocklengths, array_of_displacements, oldtype,
              newtype);
}

int multimpi_MPI_Errhandler_create(MPI_Handler_function *function,
                                   MPI_Errhandler *errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Handler_function *, MPI_Errhandler *);
  wrap func = (wrap)dlsym(handle, "mpi_Errhandler_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(function, errhandler);
}

int multimpi_MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                                  MPI_Comm peer_comm, int remote_leader,
                                  int tag, MPI_Comm *newintercomm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, MPI_Comm, int, int, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Intercomm_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(local_comm, local_leader, peer_comm, remote_leader, tag,
              newintercomm);
}

int multimpi_MPI_Type_lb(MPI_Datatype datatype, MPI_Aint *displacement) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, MPI_Aint *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_lb");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, displacement);
}

int multimpi_MPI_Errhandler_free(MPI_Errhandler *errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Errhandler *);
  wrap func = (wrap)dlsym(handle, "mpi_Errhandler_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(errhandler);
}

int multimpi_MPI_Intercomm_merge(MPI_Comm intercomm, int high,
                                 MPI_Comm *newintracomm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, int, MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Intercomm_merge");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(intercomm, high, newintracomm);
}

int multimpi_MPI_Type_match_size(int typeclass, int size,
                                 MPI_Datatype *datatype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_match_size");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(typeclass, size, datatype);
}

int multimpi_MPI_Errhandler_get(MPI_Comm comm, MPI_Errhandler *errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Errhandler *);
  wrap func = (wrap)dlsym(handle, "mpi_Errhandler_get");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, errhandler);
}

int multimpi_MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag,
                        MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, MPI_Comm, int *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Iprobe");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(source, tag, comm, flag, status);
}

int multimpi_MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval,
                               void *attribute_val) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, int, void *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_set_attr");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, type_keyval, attribute_val);
}

int multimpi_MPI_Errhandler_set(MPI_Comm comm, MPI_Errhandler errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, MPI_Errhandler);
  wrap func = (wrap)dlsym(handle, "mpi_Errhandler_set");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, errhandler);
}

int multimpi_MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source,
                       int tag, MPI_Comm comm, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, int, MPI_Datatype, int, int, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Irecv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, source, tag, comm, request);
}

int multimpi_MPI_Type_set_name(MPI_Datatype datatype, const char *type_name) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, const char *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_set_name");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, type_name);
}

int multimpi_MPI_Error_class(int errorcode, int *errorclass) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Error_class");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(errorcode, errorclass);
}

int multimpi_MPI_Ireduce(const void *sendbuf, void *recvbuf, int count,
                         MPI_Datatype datatype, MPI_Op op, int root,
                         MPI_Comm comm, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, int, MPI_Datatype, MPI_Op, int,
                      MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ireduce");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, count, datatype, op, root, comm, request);
}

int multimpi_MPI_Type_size(MPI_Datatype datatype, int *size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_size");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, size);
}

int multimpi_MPI_Error_string(int errorcode, char *string, int *resultlen) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, char *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Error_string");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(errorcode, string, resultlen);
}

int multimpi_MPI_Ireduce_scatter(const void *sendbuf, void *recvbuf,
                                 const int recvcounts[], MPI_Datatype datatype,
                                 MPI_Op op, MPI_Comm comm,
                                 MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, const int[], MPI_Datatype, MPI_Op,
                      MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ireduce_scatter");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, recvcounts, datatype, op, comm, request);
}

int multimpi_MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, MPI_Count *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_size_x");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, size);
}

int multimpi_MPI_Exscan(const void *sendbuf, void *recvbuf, int count,
                        MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, int, MPI_Datatype, MPI_Op,
                      MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Exscan");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, count, datatype, op, comm);
}

int multimpi_MPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf,
                                       int recvcount, MPI_Datatype datatype,
                                       MPI_Op op, MPI_Comm comm,
                                       MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Ireduce_scatter_block");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, recvcount, datatype, op, comm, request);
}

int multimpi_MPI_Type_struct(int count, const int *array_of_blocklengths,
                             const MPI_Aint *array_of_displacements,
                             const MPI_Datatype *array_of_types,
                             MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, const int *, const MPI_Aint *, const MPI_Datatype *,
                      MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_struct");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_blocklengths, array_of_displacements,
              array_of_types, newtype);
}

int multimpi_MPI_Fetch_and_op(const void *origin_addr, void *result_addr,
                              MPI_Datatype datatype, int target_rank,
                              MPI_Aint target_disp, MPI_Op op, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, MPI_Datatype, int, MPI_Aint, MPI_Op,
                      MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Fetch_and_op");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(origin_addr, result_addr, datatype, target_rank, target_disp, op,
              win);
}

int multimpi_MPI_Irsend(const void *buf, int count, MPI_Datatype datatype,
                        int dest, int tag, MPI_Comm comm,
                        MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Irsend");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype, MPI_Aint *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_ub");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype, displacement);
}

MPI_Fint multimpi_MPI_File_c2f(MPI_File fh) {
  if (multimpi_static_init()) {
    return NULL;
  }
  typedef MPI_Fint (*wrap)(MPI_File);
  wrap func = (wrap)dlsym(handle, "mpi_File_c2f");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return NULL;
  }
  return func(fh);
}

int multimpi_MPI_Is_thread_main(int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_Is_thread_main");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(flag);
}

int multimpi_MPI_Type_vector(int count, int blocklength, int stride,
                             MPI_Datatype oldtype, MPI_Datatype *newtype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, int, MPI_Datatype, MPI_Datatype *);
  wrap func = (wrap)dlsym(handle, "mpi_Type_vector");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, blocklength, stride, oldtype, newtype);
}

int multimpi_MPI_File_call_errhandler(MPI_File fh, int errorcode) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, int);
  wrap func = (wrap)dlsym(handle, "mpi_File_call_errhandler");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, errorcode);
}

int multimpi_MPI_Iscan(const void *sendbuf, void *recvbuf, int count,
                       MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                       MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Iscan");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, count, datatype, op, comm, request);
}

int multimpi_MPI_Unpack(const void *inbuf, int insize, int *position,
                        void *outbuf, int outcount, MPI_Datatype datatype,
                        MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, int *, void *, int, MPI_Datatype,
                      MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Unpack");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(inbuf, insize, position, outbuf, outcount, datatype, comm);
}

int multimpi_MPI_File_close(MPI_File *fh) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File *);
  wrap func = (wrap)dlsym(handle, "mpi_File_close");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh);
}

int multimpi_MPI_Iscatter(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf, int recvcount,
                          MPI_Datatype recvtype, int root, MPI_Comm comm,
                          MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, int, MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Iscatter");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root,
              comm, request);
}

int multimpi_MPI_Unpack_external(const char datarep[], const void *inbuf,
                                 MPI_Aint insize, MPI_Aint *position,
                                 void *outbuf, int outcount,
                                 MPI_Datatype datatype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const char[], const void *, MPI_Aint, MPI_Aint *, void *,
                      int, MPI_Datatype);
  wrap func = (wrap)dlsym(handle, "mpi_Unpack_external");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datarep, inbuf, insize, position, outbuf, outcount, datatype);
}

int multimpi_MPI_File_create_errhandler(
    MPI_File_errhandler_function *file_errhandler_fn,
    MPI_Errhandler *errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File_errhandler_function *, MPI_Errhandler *);
  wrap func = (wrap)dlsym(handle, "mpi_File_create_errhandler");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(file_errhandler_fn, errhandler);
}

int multimpi_MPI_Iscatterv(const void *sendbuf, const int sendcounts[],
                           const int displs[], MPI_Datatype sendtype,
                           void *recvbuf, int recvcount, MPI_Datatype recvtype,
                           int root, MPI_Comm comm, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, const int[], const int[], MPI_Datatype,
                      void *, int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Iscatterv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
              recvtype, root, comm, request);
}

int multimpi_MPI_Unpublish_name(const char *service_name, MPI_Info info,
                                const char *port_name) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const char *, MPI_Info, const char *);
  wrap func = (wrap)dlsym(handle, "mpi_Unpublish_name");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(service_name, info, port_name);
}

int multimpi_MPI_File_delete(char *filename, MPI_Info info) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(char *, MPI_Info);
  wrap func = (wrap)dlsym(handle, "mpi_File_delete");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(filename, info);
}

int multimpi_MPI_Isend(const void *buf, int count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Isend");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Wait(MPI_Request *request, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Request *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Wait");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(request, status);
}

MPI_File multimpi_MPI_File_f2c(MPI_Fint fh) {
  if (multimpi_static_init()) {
    return NULL;
  }
  typedef MPI_File (*wrap)(MPI_Fint);
  wrap func = (wrap)dlsym(handle, "mpi_File_f2c");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return NULL;
  }
  return func(fh);
}

int multimpi_MPI_Issend(const void *buf, int count, MPI_Datatype datatype,
                        int dest, int tag, MPI_Comm comm,
                        MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Issend");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Waitall(int count, MPI_Request array_of_requests[],
                         MPI_Status array_of_statuses[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Request[], MPI_Status[]);
  wrap func = (wrap)dlsym(handle, "mpi_Waitall");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_requests, array_of_statuses);
}

int multimpi_MPI_File_get_amode(MPI_File fh, int *amode) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, int *);
  wrap func = (wrap)dlsym(handle, "mpi_File_get_amode");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, amode);
}

int multimpi_MPI_Keyval_create(MPI_Copy_function *copy_fn,
                               MPI_Delete_function *delete_fn, int *keyval,
                               void *extra_state) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Copy_function *, MPI_Delete_function *, int *,
                      void *);
  wrap func = (wrap)dlsym(handle, "mpi_Keyval_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(copy_fn, delete_fn, keyval, extra_state);
}

int multimpi_MPI_Waitany(int count, MPI_Request array_of_requests[], int *indx,
                         MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Request[], int *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Waitany");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_requests, indx, status);
}

int multimpi_MPI_File_get_atomicity(MPI_File fh, int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, int *);
  wrap func = (wrap)dlsym(handle, "mpi_File_get_atomicity");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, flag);
}

int multimpi_MPI_Keyval_free(int *keyval) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_Keyval_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(keyval);
}

int multimpi_MPI_Waitsome(int incount, MPI_Request array_of_requests[],
                          int *outcount, int array_of_indices[],
                          MPI_Status array_of_statuses[]) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Request[], int *, int[], MPI_Status[]);
  wrap func = (wrap)dlsym(handle, "mpi_Waitsome");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(incount, array_of_requests, outcount, array_of_indices,
              array_of_statuses);
}

int multimpi_MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset,
                                      MPI_Offset *disp) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset, MPI_Offset *);
  wrap func = (wrap)dlsym(handle, "mpi_File_get_byte_offset");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset, disp);
}

int multimpi_MPI_Lookup_name(const char *service_name, MPI_Info info,
                             char *port_name) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const char *, MPI_Info, char *);
  wrap func = (wrap)dlsym(handle, "mpi_Lookup_name");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(service_name, info, port_name);
}

int multimpi_MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info,
                              MPI_Comm comm, void *baseptr, MPI_Win *win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Aint, int, MPI_Info, MPI_Comm, void *, MPI_Win *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_allocate");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(size, disp_unit, info, comm, baseptr, win);
}

int multimpi_MPI_File_get_errhandler(MPI_File file,
                                     MPI_Errhandler *errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Errhandler *);
  wrap func = (wrap)dlsym(handle, "mpi_File_get_errhandler");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(file, errhandler);
}

int multimpi_MPI_Mprobe(int source, int tag, MPI_Comm comm,
                        MPI_Message *message, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, MPI_Comm, MPI_Message *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Mprobe");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(source, tag, comm, message, status);
}

int multimpi_MPI_Win_allocate_shared(MPI_Aint size, int disp_unit,
                                     MPI_Info info, MPI_Comm comm,
                                     void *baseptr, MPI_Win *win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Aint, int, MPI_Info, MPI_Comm, void *, MPI_Win *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_allocate_shared");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(size, disp_unit, info, comm, baseptr, win);
}

int multimpi_MPI_File_get_group(MPI_File fh, MPI_Group *group) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Group *);
  wrap func = (wrap)dlsym(handle, "mpi_File_get_group");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, group);
}

int multimpi_MPI_Mrecv(void *buf, int count, MPI_Datatype datatype,
                       MPI_Message *message, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, int, MPI_Datatype, MPI_Message *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Mrecv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, message, status);
}

int multimpi_MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, void *, MPI_Aint);
  wrap func = (wrap)dlsym(handle, "mpi_Win_attach");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, base, size);
}

int multimpi_MPI_File_get_info(MPI_File fh, MPI_Info *info_used) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Info *);
  wrap func = (wrap)dlsym(handle, "mpi_File_get_info");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, info_used);
}

int multimpi_MPI_Neighbor_allgather(const void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    int recvcount, MPI_Datatype recvtype,
                                    MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Neighbor_allgather");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
}

int multimpi_MPI_Win_call_errhandler(MPI_Win win, int errorcode) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, int);
  wrap func = (wrap)dlsym(handle, "mpi_Win_call_errhandler");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, errorcode);
}

int multimpi_MPI_File_get_position(MPI_File fh, MPI_Offset *offset) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset *);
  wrap func = (wrap)dlsym(handle, "mpi_File_get_position");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset);
}

int multimpi_MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     const int recvcounts[], const int displs[],
                                     MPI_Datatype recvtype, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, const int[],
                      const int[], MPI_Datatype, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Neighbor_allgatherv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
              recvtype, comm);
}

int multimpi_MPI_Win_complete(MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_complete");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win);
}

int multimpi_MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset *);
  wrap func = (wrap)dlsym(handle, "mpi_File_get_position_shared");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset);
}

int multimpi_MPI_Neighbor_alltoall(const void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   int recvcount, MPI_Datatype recvtype,
                                   MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Neighbor_alltoall");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
}

int multimpi_MPI_Win_create(void *base, MPI_Aint size, int disp_unit,
                            MPI_Info info, MPI_Comm comm, MPI_Win *win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, MPI_Aint, int, MPI_Info, MPI_Comm, MPI_Win *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(base, size, disp_unit, info, comm, win);
}

int multimpi_MPI_File_get_size(MPI_File fh, MPI_Offset *size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset *);
  wrap func = (wrap)dlsym(handle, "mpi_File_get_size");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, size);
}

int multimpi_MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                                    const int sdispls[], MPI_Datatype sendtype,
                                    void *recvbuf, const int recvcounts[],
                                    const int rdispls[], MPI_Datatype recvtype,
                                    MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, const int[], const int[], MPI_Datatype,
                      void *, const int[], const int[], MPI_Datatype, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Neighbor_alltoallv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
              rdispls, recvtype, comm);
}

int multimpi_MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm,
                                    MPI_Win *win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Info, MPI_Comm, MPI_Win *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_create_dynamic");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(info, comm, win);
}

int multimpi_MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype,
                                      MPI_Aint *extent) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Datatype, MPI_Aint *);
  wrap func = (wrap)dlsym(handle, "mpi_File_get_type_extent");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, datatype, extent);
}

int multimpi_MPI_Neighbor_alltoallw(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, const int[], const MPI_Aint[],
                      const MPI_Datatype[], void *, const int[],
                      const MPI_Aint[], const MPI_Datatype[], MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Neighbor_alltoallw");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts,
              rdispls, recvtypes, comm);
}

int multimpi_MPI_Win_create_errhandler(
    MPI_Win_errhandler_function *win_errhandler_fn,
    MPI_Errhandler *errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win_errhandler_function *, MPI_Errhandler *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_create_errhandler");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win_errhandler_fn, errhandler);
}

int multimpi_MPI_File_get_view(MPI_File fh, MPI_Offset *disp,
                               MPI_Datatype *etype, MPI_Datatype *filetype,
                               char *datarep) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset *, MPI_Datatype *, MPI_Datatype *,
                      char *);
  wrap func = (wrap)dlsym(handle, "mpi_File_get_view");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, disp, etype, filetype, datarep);
}

int multimpi_MPI_Op_commutative(MPI_Op op, int *commute) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Op, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Op_commutative");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(op, commute);
}

int multimpi_MPI_Win_create_keyval(
    MPI_Win_copy_attr_function *win_copy_attr_fn,
    MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
    void *extra_state) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win_copy_attr_function *,
                      MPI_Win_delete_attr_function *, int *, void *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_create_keyval");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state);
}

int multimpi_MPI_File_iread(MPI_File fh, void *buf, int count,
                            MPI_Datatype datatype, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_File_iread");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype, request);
}

int multimpi_MPI_Op_create(MPI_User_function *user_fn, int commute,
                           MPI_Op *op) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_User_function *, int, MPI_Op *);
  wrap func = (wrap)dlsym(handle, "mpi_Op_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(user_fn, commute, op);
}

int multimpi_MPI_Win_delete_attr(MPI_Win win, int win_keyval) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, int);
  wrap func = (wrap)dlsym(handle, "mpi_Win_delete_attr");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, win_keyval);
}

int multimpi_MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf,
                               int count, MPI_Datatype datatype,
                               MPIO_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset, void *, int, MPI_Datatype,
                      MPIO_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_File_iread_at");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset, buf, count, datatype, request);
}

int multimpi_MPI_Op_free(MPI_Op *op) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Op *);
  wrap func = (wrap)dlsym(handle, "mpi_Op_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(op);
}

int multimpi_MPI_Win_detach(MPI_Win win, const void *base) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, const void *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_detach");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, base);
}

int multimpi_MPI_File_iread_shared(MPI_File fh, void *buf, int count,
                                   MPI_Datatype datatype,
                                   MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_File_iread_shared");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype, request);
}

int multimpi_MPI_Open_port(MPI_Info info, char *port_name) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Info, char *);
  wrap func = (wrap)dlsym(handle, "mpi_Open_port");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(info, port_name);
}

int multimpi_MPI_Win_fence(int assert, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_fence");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(assert, win);
}

int multimpi_MPI_File_iwrite(MPI_File fh, void *buf, int count,
                             MPI_Datatype datatype, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_File_iwrite");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype, request);
}

int multimpi_MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype,
                      void *outbuf, int outsize, int *position, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int, int *,
                      MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Pack");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(inbuf, incount, datatype, outbuf, outsize, position, comm);
}

int multimpi_MPI_Win_flush(int rank, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_flush");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(rank, win);
}

int multimpi_MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, void *buf,
                                int count, MPI_Datatype datatype,
                                MPIO_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset, void *, int, MPI_Datatype,
                      MPIO_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_File_iwrite_at");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset, buf, count, datatype, request);
}

int multimpi_MPI_Pack_external(const char datarep[], const void *inbuf,
                               int incount, MPI_Datatype datatype, void *outbuf,
                               MPI_Aint outsize, MPI_Aint *position) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const char[], const void *, int, MPI_Datatype, void *,
                      MPI_Aint, MPI_Aint *);
  wrap func = (wrap)dlsym(handle, "mpi_Pack_external");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datarep, inbuf, incount, datatype, outbuf, outsize, position);
}

int multimpi_MPI_Win_flush_all(MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_flush_all");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win);
}

int multimpi_MPI_File_iwrite_shared(MPI_File fh, void *buf, int count,
                                    MPI_Datatype datatype,
                                    MPIO_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype, MPIO_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_File_iwrite_shared");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype, request);
}

int multimpi_MPI_Pack_external_size(const char datarep[], int incount,
                                    MPI_Datatype datatype, MPI_Aint *size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const char[], int, MPI_Datatype, MPI_Aint *);
  wrap func = (wrap)dlsym(handle, "mpi_Pack_external_size");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datarep, incount, datatype, size);
}

int multimpi_MPI_Win_flush_local(int rank, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_flush_local");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(rank, win);
}

int multimpi_MPI_File_open(MPI_Comm comm, char *filename, int amode,
                           MPI_Info info, MPI_File *fh) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Comm, char *, int, MPI_Info, MPI_File *);
  wrap func = (wrap)dlsym(handle, "mpi_File_open");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, filename, amode, info, fh);
}

int multimpi_MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm,
                           int *size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Datatype, MPI_Comm, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Pack_size");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(incount, datatype, comm, size);
}

int multimpi_MPI_Win_flush_local_all(MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_flush_local_all");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win);
}

int multimpi_MPI_File_preallocate(MPI_File fh, MPI_Offset size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset);
  wrap func = (wrap)dlsym(handle, "mpi_File_preallocate");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, size);
}

int multimpi_MPI_Win_free(MPI_Win *win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win);
}

int multimpi_MPI_File_read(MPI_File fh, void *buf, int count,
                           MPI_Datatype datatype, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_read");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype, status);
}

int multimpi_MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, MPI_Comm, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Probe");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(source, tag, comm, status);
}

int multimpi_MPI_Win_free_keyval(int *win_keyval) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_free_keyval");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win_keyval);
}

int multimpi_MPI_File_read_all(MPI_File fh, void *buf, int count,
                               MPI_Datatype datatype, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_read_all");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype, status);
}

int multimpi_MPI_Publish_name(const char *service_name, MPI_Info info,
                              const char *port_name) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const char *, MPI_Info, const char *);
  wrap func = (wrap)dlsym(handle, "mpi_Publish_name");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(service_name, info, port_name);
}

int multimpi_MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val,
                              int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, int, void *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_get_attr");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, win_keyval, attribute_val, flag);
}

int multimpi_MPI_File_read_all_begin(MPI_File fh, void *buf, int count,
                                     MPI_Datatype datatype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype);
  wrap func = (wrap)dlsym(handle, "mpi_File_read_all_begin");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype);
}

int multimpi_MPI_Put(const void *origin_addr, int origin_count,
                     MPI_Datatype origin_datatype, int target_rank,
                     MPI_Aint target_disp, int target_count,
                     MPI_Datatype target_datatype, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, MPI_Aint, int,
                      MPI_Datatype, MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Put");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(origin_addr, origin_count, origin_datatype, target_rank,
              target_disp, target_count, target_datatype, win);
}

int multimpi_MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, MPI_Errhandler *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_get_errhandler");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, errhandler);
}

int multimpi_MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_read_all_end");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, status);
}

int multimpi_MPI_Query_thread(int *provided) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_Query_thread");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(provided);
}

int multimpi_MPI_Win_get_group(MPI_Win win, MPI_Group *group) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, MPI_Group *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_get_group");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, group);
}

int multimpi_MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf,
                              int count, MPI_Datatype datatype,
                              MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset, void *, int, MPI_Datatype,
                      MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_read_at");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset, buf, count, datatype, status);
}

int multimpi_MPI_Raccumulate(const void *origin_addr, int origin_count,
                             MPI_Datatype origin_datatype, int target_rank,
                             MPI_Aint target_disp, int target_count,
                             MPI_Datatype target_datatype, MPI_Op op,
                             MPI_Win win, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, MPI_Aint, int,
                      MPI_Datatype, MPI_Op, MPI_Win, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Raccumulate");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(origin_addr, origin_count, origin_datatype, target_rank,
              target_disp, target_count, target_datatype, op, win, request);
}

int multimpi_MPI_Win_get_info(MPI_Win win, MPI_Info *info_used) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, MPI_Info *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_get_info");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, info_used);
}

int multimpi_MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf,
                                  int count, MPI_Datatype datatype,
                                  MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset, void *, int, MPI_Datatype,
                      MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_read_at_all");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset, buf, count, datatype, status);
}

int multimpi_MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source,
                      int tag, MPI_Comm comm, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, int, MPI_Datatype, int, int, MPI_Comm,
                      MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Recv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, source, tag, comm, status);
}

int multimpi_MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, char *, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_get_name");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, win_name, resultlen);
}

int multimpi_MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset,
                                        void *buf, int count,
                                        MPI_Datatype datatype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset, void *, int, MPI_Datatype);
  wrap func = (wrap)dlsym(handle, "mpi_File_read_at_all_begin");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset, buf, count, datatype);
}

int multimpi_MPI_Recv_init(void *buf, int count, MPI_Datatype datatype,
                           int source, int tag, MPI_Comm comm,
                           MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, int, MPI_Datatype, int, int, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Recv_init");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, source, tag, comm, request);
}

int multimpi_MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, int, int, MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_lock");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(lock_type, rank, assert, win);
}

int multimpi_MPI_File_read_at_all_end(MPI_File fh, void *buf,
                                      MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_read_at_all_end");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, status);
}

int multimpi_MPI_Reduce(const void *sendbuf, void *recvbuf, int count,
                        MPI_Datatype datatype, MPI_Op op, int root,
                        MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, int, MPI_Datatype, MPI_Op, int,
                      MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Reduce");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, count, datatype, op, root, comm);
}

int multimpi_MPI_Win_lock_all(int assert, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_lock_all");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(assert, win);
}

int multimpi_MPI_File_read_ordered(MPI_File fh, void *buf, int count,
                                   MPI_Datatype datatype, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_read_ordered");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype, status);
}

int multimpi_MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count,
                              MPI_Datatype datatype, MPI_Op op) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, int, MPI_Datatype, MPI_Op);
  wrap func = (wrap)dlsym(handle, "mpi_Reduce_local");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(inbuf, inoutbuf, count, datatype, op);
}

int multimpi_MPI_Win_post(MPI_Group group, int assert, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, int, MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_post");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group, assert, win);
}

int multimpi_MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count,
                                         MPI_Datatype datatype) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype);
  wrap func = (wrap)dlsym(handle, "mpi_File_read_ordered_begin");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype);
}

int multimpi_MPI_Reduce_scatter(const void *sendbuf, void *recvbuf,
                                const int recvcounts[], MPI_Datatype datatype,
                                MPI_Op op, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, const int[], MPI_Datatype, MPI_Op,
                      MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Reduce_scatter");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, recvcounts, datatype, op, comm);
}

int multimpi_MPI_Win_set_attr(MPI_Win win, int win_keyval,
                              void *attribute_val) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, int, void *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_set_attr");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, win_keyval, attribute_val);
}

int multimpi_MPI_File_read_ordered_end(MPI_File fh, void *buf,
                                       MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_read_ordered_end");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, status);
}

int multimpi_MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf,
                                      int recvcount, MPI_Datatype datatype,
                                      MPI_Op op, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, int, MPI_Datatype, MPI_Op,
                      MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Reduce_scatter_block");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, recvcount, datatype, op, comm);
}

int multimpi_MPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, MPI_Errhandler);
  wrap func = (wrap)dlsym(handle, "mpi_Win_set_errhandler");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, errhandler);
}

int multimpi_MPI_File_read_shared(MPI_File fh, void *buf, int count,
                                  MPI_Datatype datatype, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_read_shared");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype, status);
}

int multimpi_MPI_Register_datarep(
    char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
    MPI_Datarep_conversion_function *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(char *, MPI_Datarep_conversion_function *,
                      MPI_Datarep_conversion_function *,
                      MPI_Datarep_extent_function *, void *);
  wrap func = (wrap)dlsym(handle, "mpi_Register_datarep");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datarep, read_conversion_fn, write_conversion_fn,
              dtype_file_extent_fn, extra_state);
}

int multimpi_MPI_Win_set_info(MPI_Win win, MPI_Info info) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, MPI_Info);
  wrap func = (wrap)dlsym(handle, "mpi_Win_set_info");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, info);
}

int multimpi_MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset, int);
  wrap func = (wrap)dlsym(handle, "mpi_File_seek");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset, whence);
}

int multimpi_MPI_Request_free(MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Request_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(request);
}

int multimpi_MPI_Win_set_name(MPI_Win win, const char *win_name) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, const char *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_set_name");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, win_name);
}

int multimpi_MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset, int);
  wrap func = (wrap)dlsym(handle, "mpi_File_seek_shared");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, offset, whence);
}

int multimpi_MPI_Request_get_status(MPI_Request request, int *flag,
                                    MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Request, int *, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_Request_get_status");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(request, flag, status);
}

int multimpi_MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size,
                                  int *disp_unit, void *baseptr) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, int, MPI_Aint *, int *, void *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_shared_query");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, rank, size, disp_unit, baseptr);
}

int multimpi_MPI_File_set_atomicity(MPI_File fh, int flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, int);
  wrap func = (wrap)dlsym(handle, "mpi_File_set_atomicity");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, flag);
}

int multimpi_MPI_Rget(void *origin_addr, int origin_count,
                      MPI_Datatype origin_datatype, int target_rank,
                      MPI_Aint target_disp, int target_count,
                      MPI_Datatype target_datatype, MPI_Win win,
                      MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(void *, int, MPI_Datatype, int, MPI_Aint, int,
                      MPI_Datatype, MPI_Win, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Rget");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(origin_addr, origin_count, origin_datatype, target_rank,
              target_disp, target_count, target_datatype, win, request);
}

int multimpi_MPI_Win_start(MPI_Group group, int assert, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Group, int, MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_start");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group, assert, win);
}

int multimpi_MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Errhandler);
  wrap func = (wrap)dlsym(handle, "mpi_File_set_errhandler");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(file, errhandler);
}

int multimpi_MPI_Rget_accumulate(const void *origin_addr, int origin_count,
                                 MPI_Datatype origin_datatype,
                                 void *result_addr, int result_count,
                                 MPI_Datatype result_datatype, int target_rank,
                                 MPI_Aint target_disp, int target_count,
                                 MPI_Datatype target_datatype, MPI_Op op,
                                 MPI_Win win, MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op,
                      MPI_Win, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Rget_accumulate");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(origin_addr, origin_count, origin_datatype, result_addr,
              result_count, result_datatype, target_rank, target_disp,
              target_count, target_datatype, op, win, request);
}

int multimpi_MPI_Win_sync(MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_sync");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win);
}

int multimpi_MPI_File_set_info(MPI_File fh, MPI_Info info) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Info);
  wrap func = (wrap)dlsym(handle, "mpi_File_set_info");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, info);
}

int multimpi_MPI_Rput(const void *origin_addr, int origin_count,
                      MPI_Datatype origin_datatype, int target_rank,
                      MPI_Aint target_disp, int target_count,
                      MPI_Datatype target_datatype, MPI_Win win,
                      MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, MPI_Aint, int,
                      MPI_Datatype, MPI_Win, MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Rput");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(origin_addr, origin_count, origin_datatype, target_rank,
              target_disp, target_count, target_datatype, win, request);
}

int multimpi_MPI_Win_test(MPI_Win win, int *flag) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Win_test");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win, flag);
}

int multimpi_MPI_File_set_size(MPI_File fh, MPI_Offset size) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset);
  wrap func = (wrap)dlsym(handle, "mpi_File_set_size");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, size);
}

int multimpi_MPI_Rsend(const void *buf, int count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Rsend");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm);
}

int multimpi_MPI_Win_unlock(int rank, MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(int, MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_unlock");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(rank, win);
}

int multimpi_MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype,
                               MPI_Datatype filetype, char *datarep,
                               MPI_Info info) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, MPI_Offset, MPI_Datatype, MPI_Datatype, char *,
                      MPI_Info);
  wrap func = (wrap)dlsym(handle, "mpi_File_set_view");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, disp, etype, filetype, datarep, info);
}

int multimpi_MPI_Rsend_init(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm,
                            MPI_Request *request) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, int, int, MPI_Comm,
                      MPI_Request *);
  wrap func = (wrap)dlsym(handle, "mpi_Rsend_init");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm, request);
}

int multimpi_MPI_Win_unlock_all(MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_unlock_all");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win);
}

int multimpi_MPI_File_sync(MPI_File fh) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File);
  wrap func = (wrap)dlsym(handle, "mpi_File_sync");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh);
}

int multimpi_MPI_Scan(const void *sendbuf, void *recvbuf, int count,
                      MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, void *, int, MPI_Datatype, MPI_Op,
                      MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Scan");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, count, datatype, op, comm);
}

int multimpi_MPI_Win_wait(MPI_Win win) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_Win);
  wrap func = (wrap)dlsym(handle, "mpi_Win_wait");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(win);
}

int multimpi_MPI_File_write(MPI_File fh, void *buf, int count,
                            MPI_Datatype datatype, MPI_Status *status) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(MPI_File, void *, int, MPI_Datatype, MPI_Status *);
  wrap func = (wrap)dlsym(handle, "mpi_File_write");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(fh, buf, count, datatype, status);
}

int multimpi_MPI_Scatter(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, void *recvbuf, int recvcount,
                         MPI_Datatype recvtype, int root, MPI_Comm comm) {
  if (multimpi_static_init()) {
    return 1;
  }
  typedef int (*wrap)(const void *, int, MPI_Datatype, void *, int,
                      MPI_Datatype, int, MPI_Comm);
  wrap func = (wrap)dlsym(handle, "mpi_Scatter");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root,
              comm);
}

double multimpi_MPI_Wtick() {
  if (multimpi_static_init()) {
    return 0;
  }
  typedef double (*wrap)();
  wrap func = (wrap)dlsym(handle, "mpi_Wtick");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 0;
  }
  return func();
}

double multimpi_MPI_Wtime() {
  if (multimpi_static_init()) {
    return 0;
  }
  typedef double (*wrap)();
  wrap func = (wrap)dlsym(handle, "mpi_Wtime");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 0;
  }
  return func();
}
