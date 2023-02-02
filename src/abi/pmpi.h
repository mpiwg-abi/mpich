/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/*  */
#ifndef PMPI_INCLUDED
#define PMPI_INCLUDED

/* Keep C++ compilers from getting confused */
#if defined(__cplusplus)
extern "C" {
#endif

/* Define some null objects */
#define PMPI_COMM_NULL      ((PMPI_Comm)0x04000000)
#define PMPI_OP_NULL        ((PMPI_Op)0x18000000)
#define PMPI_GROUP_NULL     ((PMPI_Group)0x08000000)
#define PMPI_DATATYPE_NULL  ((PMPI_Datatype)0x0c000000)
#define PMPI_REQUEST_NULL   ((PMPI_Request)0x2c000000)
#define PMPI_ERRHANDLER_NULL ((PMPI_Errhandler)0x14000000)
#define PMPI_MESSAGE_NULL   ((PMPI_Message)0x2c000000)
#define PMPI_MESSAGE_NO_PROC ((PMPI_Message)0x6c000000)
#define PMPIX_STREAM_NULL   ((PMPIX_Stream)0x3c000000)

/* Results of the compare operations. */
#define PMPI_IDENT     0
#define PMPI_CONGRUENT 1
#define PMPI_SIMILAR   2
#define PMPI_UNEQUAL   3

typedef int PMPI_Datatype;
#define PMPI_CHAR           ((PMPI_Datatype)0x4c000101)
#define PMPI_SIGNED_CHAR    ((PMPI_Datatype)0x4c000118)
#define PMPI_UNSIGNED_CHAR  ((PMPI_Datatype)0x4c000102)
#define PMPI_BYTE           ((PMPI_Datatype)0x4c00010d)
#define PMPI_WCHAR          ((PMPI_Datatype)0x4c00040e)
#define PMPI_SHORT          ((PMPI_Datatype)0x4c000203)
#define PMPI_UNSIGNED_SHORT ((PMPI_Datatype)0x4c000204)
#define PMPI_INT            ((PMPI_Datatype)0x4c000405)
#define PMPI_UNSIGNED       ((PMPI_Datatype)0x4c000406)
#define PMPI_LONG           ((PMPI_Datatype)0x4c000807)
#define PMPI_UNSIGNED_LONG  ((PMPI_Datatype)0x4c000808)
#define PMPI_FLOAT          ((PMPI_Datatype)0x4c00040a)
#define PMPI_DOUBLE         ((PMPI_Datatype)0x4c00080b)
#define PMPI_LONG_DOUBLE    ((PMPI_Datatype)0x4c00100c)
#define PMPI_LONG_LONG_INT  ((PMPI_Datatype)0x4c000809)
#define PMPI_UNSIGNED_LONG_LONG ((PMPI_Datatype)0x4c000819)
#define PMPI_LONG_LONG      PMPI_LONG_LONG_INT

#define PMPI_PACKED         ((PMPI_Datatype)0x4c00010f)
#define PMPI_LB             ((PMPI_Datatype)0x4c000010)
#define PMPI_UB             ((PMPI_Datatype)0x4c000011)

#define PMPI_FLOAT_INT         ((PMPI_Datatype)0x8c000000)
#define PMPI_DOUBLE_INT        ((PMPI_Datatype)0x8c000001)
#define PMPI_LONG_INT          ((PMPI_Datatype)0x8c000002)
#define PMPI_SHORT_INT         ((PMPI_Datatype)0x8c000003)
#define PMPI_2INT              ((PMPI_Datatype)0x4c000816)
#define PMPI_LONG_DOUBLE_INT   ((PMPI_Datatype)0x8c000004)

/* Fortran types */
#define PMPI_COMPLEX           ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_DOUBLE_COMPLEX    ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_LOGICAL           ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_REAL              ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_DOUBLE_PRECISION  ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_INTEGER           ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_2INTEGER          ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_2REAL             ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_2DOUBLE_PRECISION ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_CHARACTER         ((PMPI_Datatype)PMPI_DATATYPE_NULL)

/* Size-specific types (see MPI-2, 10.2.5) */
#define PMPI_REAL4             ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_REAL8             ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_REAL16            ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_COMPLEX8          ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_COMPLEX16         ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_COMPLEX32         ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_INTEGER1          ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_INTEGER2          ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_INTEGER4          ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_INTEGER8          ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_INTEGER16         ((PMPI_Datatype)PMPI_DATATYPE_NULL)

/* C99 fixed-width datatypes */
#define PMPI_INT8_T            ((PMPI_Datatype)0x4c000137)
#define PMPI_INT16_T           ((PMPI_Datatype)0x4c000238)
#define PMPI_INT32_T           ((PMPI_Datatype)0x4c000439)
#define PMPI_INT64_T           ((PMPI_Datatype)0x4c00083a)
#define PMPI_UINT8_T           ((PMPI_Datatype)0x4c00013b)
#define PMPI_UINT16_T          ((PMPI_Datatype)0x4c00023c)
#define PMPI_UINT32_T          ((PMPI_Datatype)0x4c00043d)
#define PMPI_UINT64_T          ((PMPI_Datatype)0x4c00083e)

/* other C99 types */
#define PMPI_C_BOOL                 ((PMPI_Datatype)0x4c00013f)
#define PMPI_C_FLOAT_COMPLEX        ((PMPI_Datatype)0x4c000840)
#define PMPI_C_COMPLEX              PMPI_C_FLOAT_COMPLEX
#define PMPI_C_DOUBLE_COMPLEX       ((PMPI_Datatype)0x4c001041)
#define PMPI_C_LONG_DOUBLE_COMPLEX  ((PMPI_Datatype)0x4c002042)
/* other extension types */
#define PMPIX_C_FLOAT16             ((PMPI_Datatype)0x4c000246)

/* address/offset types */
#define PMPI_AINT          ((PMPI_Datatype)0x4c000843)
#define PMPI_OFFSET        ((PMPI_Datatype)0x4c000844)
#define PMPI_COUNT         ((PMPI_Datatype)0x4c000845)

/* MPI-3 C++ types */
#define PMPI_CXX_BOOL                ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_CXX_FLOAT_COMPLEX       ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_CXX_DOUBLE_COMPLEX      ((PMPI_Datatype)PMPI_DATATYPE_NULL)
#define PMPI_CXX_LONG_DOUBLE_COMPLEX ((PMPI_Datatype)PMPI_DATATYPE_NULL)

/* typeclasses */
#define PMPI_TYPECLASS_REAL 1
#define PMPI_TYPECLASS_INTEGER 2
#define PMPI_TYPECLASS_COMPLEX 3

/* Communicators */
typedef int PMPI_Comm;
#define PMPI_COMM_WORLD ((PMPI_Comm)0x44000000)
#define PMPI_COMM_SELF  ((PMPI_Comm)0x44000001)

/* Groups */
typedef int PMPI_Group;
#define PMPI_GROUP_EMPTY ((PMPI_Group)0x48000000)

/* RMA and Windows */
typedef int PMPI_Win;
#define PMPI_WIN_NULL ((PMPI_Win)0x20000000)

/* for session */
typedef int PMPI_Session;
#define PMPI_SESSION_NULL     ((PMPI_Session)0x38000000)

/* File and IO */
/* This define lets ROMIO know that PMPI_File has been defined */
#define PMPI_FILE_DEFINED
/* ROMIO uses a pointer for PMPI_File objects.  This must be the same definition
   as in src/mpi/romio/include/mpio.h.in  */
typedef struct ADIOI_FileD *PMPI_File;
#define PMPI_FILE_NULL ((PMPI_File)0)

/* Collective operations */
typedef int PMPI_Op;

#define PMPI_MAX     (PMPI_Op)(0x58000001)
#define PMPI_MIN     (PMPI_Op)(0x58000002)
#define PMPI_SUM     (PMPI_Op)(0x58000003)
#define PMPI_PROD    (PMPI_Op)(0x58000004)
#define PMPI_LAND    (PMPI_Op)(0x58000005)
#define PMPI_BAND    (PMPI_Op)(0x58000006)
#define PMPI_LOR     (PMPI_Op)(0x58000007)
#define PMPI_BOR     (PMPI_Op)(0x58000008)
#define PMPI_LXOR    (PMPI_Op)(0x58000009)
#define PMPI_BXOR    (PMPI_Op)(0x5800000a)
#define PMPI_MINLOC  (PMPI_Op)(0x5800000b)
#define PMPI_MAXLOC  (PMPI_Op)(0x5800000c)
#define PMPI_REPLACE (PMPI_Op)(0x5800000d)
#define PMPI_NO_OP   (PMPI_Op)(0x5800000e)

#define PMPI_TAG_UB           0x64400001
#define PMPI_HOST             0x64400003
#define PMPI_IO               0x64400005
#define PMPI_WTIME_IS_GLOBAL  0x64400007
#define PMPI_UNIVERSE_SIZE    0x64400009
#define PMPI_LASTUSEDCODE     0x6440000b
#define PMPI_APPNUM           0x6440000d

/* In addition, there are 5 predefined window attributes that are
   defined for every window */
#define PMPI_WIN_BASE          0x66000001
#define PMPI_WIN_SIZE          0x66000003
#define PMPI_WIN_DISP_UNIT     0x66000005
#define PMPI_WIN_CREATE_FLAVOR 0x66000007
#define PMPI_WIN_MODEL         0x66000009

/* These are only guesses; make sure you change them in mpif.h as well */
#define PMPI_MAX_PROCESSOR_NAME 128
#define PMPI_MAX_LIBRARY_VERSION_STRING 8192
#define PMPI_MAX_ERROR_STRING   512
#define PMPI_MAX_PORT_NAME      256
#define PMPI_MAX_OBJECT_NAME    128
#define PMPI_MAX_STRINGTAG_LEN  256
#define PMPI_MAX_PSET_NAME_LEN  256

/* Pre-defined constants */
#define PMPI_UNDEFINED      (-32766)
#define PMPI_KEYVAL_INVALID 0x24000000

/* MPI-3 window flavors */
typedef enum MPIR_Win_flavor {
    PMPI_WIN_FLAVOR_CREATE      = 1,
    PMPI_WIN_FLAVOR_ALLOCATE    = 2,
    PMPI_WIN_FLAVOR_DYNAMIC     = 3,
    PMPI_WIN_FLAVOR_SHARED      = 4
} MPIR_Win_flavor_t;

/* MPI-3 window consistency models */
typedef enum MPIR_Win_model {
    PMPI_WIN_SEPARATE   = 1,
    PMPI_WIN_UNIFIED    = 2
} MPIR_Win_model_t;

/* Upper bound on the overhead in bsend for each message buffer */
#define PMPI_BSEND_OVERHEAD 96

/* Topology types */
typedef enum MPIR_Topo_type { PMPI_GRAPH=1, PMPI_CART=2, PMPI_DIST_GRAPH=3 } MPIR_Topo_type;

#define PMPI_BOTTOM      (void *)0
extern int * const PMPI_UNWEIGHTED;
extern int * const PMPI_WEIGHTS_EMPTY;

#define PMPI_PROC_NULL   (-1)
#define PMPI_ANY_SOURCE 	(-2)
#define PMPI_ROOT        (-3)
#define PMPI_ANY_TAG     (-1)

#define PMPI_LOCK_EXCLUSIVE  234
#define PMPI_LOCK_SHARED     235

/* C functions */
typedef void (PMPI_Handler_function) ( PMPI_Comm *, int *, ... );
typedef int (PMPI_Comm_copy_attr_function)(PMPI_Comm, int, void *, void *, 
					  void *, int *);
typedef int (PMPI_Comm_delete_attr_function)(PMPI_Comm, int, void *, void *);
typedef int (PMPI_Type_copy_attr_function)(PMPI_Datatype, int, void *, void *, 
					  void *, int *);
typedef int (PMPI_Type_delete_attr_function)(PMPI_Datatype, int, void *, void *);
typedef int (PMPI_Win_copy_attr_function)(PMPI_Win, int, void *, void *, void *,
					 int *);
typedef int (PMPI_Win_delete_attr_function)(PMPI_Win, int, void *, void *);
/* added in MPI-2.2 */
typedef void (PMPI_Comm_errhandler_function)(PMPI_Comm *, int *, ...);
typedef void (PMPI_File_errhandler_function)(PMPI_File *, int *, ...);
typedef void (PMPI_Win_errhandler_function)(PMPI_Win *, int *, ...);
typedef void (PMPI_Session_errhandler_function)(PMPI_Session *, int *, ...);
/* names that were added in MPI-2.0 and deprecated in MPI-2.2 */
typedef PMPI_Comm_errhandler_function PMPI_Comm_errhandler_fn;
typedef PMPI_File_errhandler_function PMPI_File_errhandler_fn;
typedef PMPI_Win_errhandler_function PMPI_Win_errhandler_fn;
typedef PMPI_Session_errhandler_function PMPI_Session_errhandler_fn;

/* Built in (0x1 in 30-31), errhandler (0x5 in bits 26-29, allkind (0
   in 22-25), index in the low bits */
#define PMPI_ERRORS_ARE_FATAL ((PMPI_Errhandler)0x54000000)
#define PMPI_ERRORS_RETURN    ((PMPI_Errhandler)0x54000001)
/* MPIR_ERRORS_THROW_EXCEPTIONS is not part of the MPI standard, it is here to
   facilitate the c++ binding which has MPI::ERRORS_THROW_EXCEPTIONS. 
   Using the MPIR prefix preserved the PMPI_ names for objects defined by
   the standard. */
#define MPIR_ERRORS_THROW_EXCEPTIONS ((PMPI_Errhandler)0x54000002)
#define PMPI_ERRORS_ABORT     ((PMPI_Errhandler)0x54000003)
typedef int PMPI_Errhandler;

/* Make the C names for the dup function mixed case.
   This is required for systems that use all uppercase names for Fortran 
   externals.  */
/* MPI 1 names */
#define PMPI_NULL_COPY_FN   ((PMPI_Copy_function *)0)
#define PMPI_NULL_DELETE_FN ((PMPI_Delete_function *)0)
#define PMPI_DUP_FN         MPIR_Dup_fn
/* MPI 2 names */
#define PMPI_COMM_NULL_COPY_FN ((PMPI_Comm_copy_attr_function*)0)
#define PMPI_COMM_NULL_DELETE_FN ((PMPI_Comm_delete_attr_function*)0)
#define PMPI_COMM_DUP_FN  ((PMPI_Comm_copy_attr_function *)PMPI_DUP_FN)
#define PMPI_WIN_NULL_COPY_FN ((PMPI_Win_copy_attr_function*)0)
#define PMPI_WIN_NULL_DELETE_FN ((PMPI_Win_delete_attr_function*)0)
#define PMPI_WIN_DUP_FN   ((PMPI_Win_copy_attr_function*)PMPI_DUP_FN)
#define PMPI_TYPE_NULL_COPY_FN ((PMPI_Type_copy_attr_function*)0)
#define PMPI_TYPE_NULL_DELETE_FN ((PMPI_Type_delete_attr_function*)0)
#define PMPI_TYPE_DUP_FN ((PMPI_Type_copy_attr_function*)PMPI_DUP_FN)

/* MPI request objects */
typedef int PMPI_Request;

/* MPI message objects for Mprobe and related functions */
typedef int PMPI_Message;

/* Generalized requests extensions */
typedef int PMPIX_Grequest_class;

/* MPI stream objects */
typedef int PMPIX_Stream;

/* MPI Attribute copy and delete functions */
typedef int (PMPI_Copy_function) ( PMPI_Comm, int, void *, void *, void *, int * );
typedef int (PMPI_Delete_function) ( PMPI_Comm, int, void *, void * );

#define PMPI_VERSION    4
#define PMPI_SUBVERSION 0
#define MPICH_NAME     4
#define MPICH         1
#define MPICH_HAS_C2F  1


/* MPICH_VERSION is the version string. MPICH_NUMVERSION is the
 * numeric version that can be used in numeric comparisons.
 *
 * MPICH_VERSION uses the following format:
 * Version: [MAJ].[MIN].[REV][EXT][EXT_NUMBER]
 * Example: 1.0.7rc1 has
 *          MAJ = 1
 *          MIN = 0
 *          REV = 7
 *          EXT = rc
 *          EXT_NUMBER = 1
 *
 * MPICH_NUMVERSION will convert EXT to a format number:
 *          ALPHA (a) = 0
 *          BETA (b)  = 1
 *          RC (rc)   = 2
 *          PATCH (p) = 3
 * Regular releases are treated as patch 0
 *
 * Numeric version will have 1 digit for MAJ, 2 digits for MIN, 2
 * digits for REV, 1 digit for EXT and 2 digits for EXT_NUMBER. So,
 * 1.0.7rc1 will have the numeric version 10007201.
 */
#define MPICH_VERSION "4.2a1"
#define MPICH_NUMVERSION 40200001

#define MPICH_RELEASE_TYPE_ALPHA  0
#define MPICH_RELEASE_TYPE_BETA   1
#define MPICH_RELEASE_TYPE_RC     2
#define MPICH_RELEASE_TYPE_PATCH  3

#define MPICH_CALC_VERSION(MAJOR, MINOR, REVISION, TYPE, PATCH) \
    (((MAJOR) * 10000000) + ((MINOR) * 100000) + ((REVISION) * 1000) + ((TYPE) * 100) + (PATCH))

/* for the datatype decoders */
enum MPIR_Combiner_enum {
    PMPI_COMBINER_NAMED            = 1,
    PMPI_COMBINER_DUP              = 2,
    PMPI_COMBINER_CONTIGUOUS       = 3, 
    PMPI_COMBINER_VECTOR           = 4,
    PMPI_COMBINER_HVECTOR_INTEGER  = 5,
    PMPI_COMBINER_HVECTOR          = 6,
    PMPI_COMBINER_INDEXED          = 7,
    PMPI_COMBINER_HINDEXED_INTEGER = 8, 
    PMPI_COMBINER_HINDEXED         = 9, 
    PMPI_COMBINER_INDEXED_BLOCK    = 10, 
    PMPI_COMBINER_STRUCT_INTEGER   = 11,
    PMPI_COMBINER_STRUCT           = 12,
    PMPI_COMBINER_SUBARRAY         = 13,
    PMPI_COMBINER_DARRAY           = 14,
    PMPI_COMBINER_F90_REAL         = 15,
    PMPI_COMBINER_F90_COMPLEX      = 16,
    PMPI_COMBINER_F90_INTEGER      = 17,
    PMPI_COMBINER_RESIZED          = 18,
    PMPI_COMBINER_HINDEXED_BLOCK   = 19
};

/* for info */
typedef int PMPI_Info;
#define PMPI_INFO_NULL         ((PMPI_Info)0x1c000000)
#define PMPI_INFO_ENV          ((PMPI_Info)0x5c000001)
#define PMPI_MAX_INFO_KEY       255
#define PMPI_MAX_INFO_VAL      1024

/* for subarray and darray constructors */
#define PMPI_ORDER_C              56
#define PMPI_ORDER_FORTRAN        57
#define PMPI_DISTRIBUTE_BLOCK    121
#define PMPI_DISTRIBUTE_CYCLIC   122
#define PMPI_DISTRIBUTE_NONE     123
#define PMPI_DISTRIBUTE_DFLT_DARG -49767

#define PMPI_IN_PLACE  (void *) -1

/* asserts for one-sided communication */
#define PMPI_MODE_NOCHECK      1024
#define PMPI_MODE_NOSTORE      2048
#define PMPI_MODE_NOPUT        4096
#define PMPI_MODE_NOPRECEDE    8192
#define PMPI_MODE_NOSUCCEED   16384 

/* predefined types for PMPI_Comm_split_type */
#define PMPI_COMM_TYPE_SHARED    1
#define PMPI_COMM_TYPE_HW_GUIDED 2
#define PMPI_COMM_TYPE_HW_UNGUIDED 3

/* MPICH-specific types */
#define PMPIX_COMM_TYPE_NEIGHBORHOOD 4

/* Definitions that are determined by configure. */
typedef long PMPI_Aint;
typedef int PMPI_Fint;
typedef long PMPI_Count;

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static const PMPI_Datatype mpich_mpi_aint   MPICH_ATTR_TYPE_TAG(PMPI_Aint)   = PMPI_AINT;
#endif

/* FIXME: The following two definition are not defined by MPI and must not be
   included in the mpi.h file, as the MPI namespace is reserved to the MPI 
   standard */
#define PMPI_AINT_FMT_DEC_SPEC "%ld"
#define PMPI_AINT_FMT_HEX_SPEC "%lx"

/* Let ROMIO know that PMPI_Offset is already defined */
#define HAVE_MPI_OFFSET
/* PMPI_OFFSET_TYPEDEF is set in configure and is 
      typedef $PMPI_OFFSET PMPI_Offset;
   where $PMPI_OFFSET is the correct C type */
typedef long PMPI_Offset;

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static const PMPI_Datatype mpich_mpi_offset MPICH_ATTR_TYPE_TAG(PMPI_Offset) = PMPI_OFFSET;
#endif

/* The order of these elements must match that in mpif.h, mpi_f08_types.f90,
   and mpi_c_interface_types.f90 */
typedef struct PMPI_Status {
    int count_lo;
    int count_hi_and_cancelled;
    int PMPI_SOURCE;
    int PMPI_TAG;
    int PMPI_ERROR;
} PMPI_Status;

/* User combination function */
typedef void (PMPI_User_function) ( void *, void *, int *, PMPI_Datatype * );
typedef void (PMPI_User_function_c) ( void *, void *, PMPI_Count *, PMPI_Datatype * );

/* types for the PMPI_T_ interface */
struct MPIR_T_enum_s;
struct MPIR_T_cvar_handle_s;
struct MPIR_T_pvar_handle_s;
struct MPIR_T_pvar_session_s;
struct MPIR_T_event_registration_s;
struct MPIR_T_event_instance_s;

typedef struct MPIR_T_enum_s * PMPI_T_enum;
typedef struct MPIR_T_cvar_handle_s * PMPI_T_cvar_handle;
typedef struct MPIR_T_pvar_handle_s * PMPI_T_pvar_handle;
typedef struct MPIR_T_pvar_session_s * PMPI_T_pvar_session;
typedef struct MPIR_T_event_registration_s * PMPI_T_event_registration;
typedef struct MPIR_T_event_instance_s * PMPI_T_event_instance;

/* extra const at front would be safer, but is incompatible with PMPI_T_ prototypes */
extern struct MPIR_T_pvar_handle_s * const PMPI_T_PVAR_ALL_HANDLES;

#define PMPI_T_ENUM_NULL         ((PMPI_T_enum)NULL)
#define PMPI_T_CVAR_HANDLE_NULL  ((PMPI_T_cvar_handle)NULL)
#define PMPI_T_PVAR_HANDLE_NULL  ((PMPI_T_pvar_handle)NULL)
#define PMPI_T_PVAR_SESSION_NULL ((PMPI_T_pvar_session)NULL)

/* the PMPI_T_ interface requires that these VERBOSITY constants occur in this
 * relative order with increasing values */
typedef enum MPIR_T_verbosity_t {
    /* don't name-shift this if/when PMPI_T_ is accepted, this is an MPICH-only
     * extension */
    PMPI_T_VERBOSITY_INVALID = 0,

    /* arbitrarily shift values to aid debugging and reduce accidental errors */
    PMPI_T_VERBOSITY_USER_BASIC = 221,
    PMPI_T_VERBOSITY_USER_DETAIL,
    PMPI_T_VERBOSITY_USER_ALL,

    PMPI_T_VERBOSITY_TUNER_BASIC,
    PMPI_T_VERBOSITY_TUNER_DETAIL,
    PMPI_T_VERBOSITY_TUNER_ALL,

    PMPI_T_VERBOSITY_MPIDEV_BASIC,
    PMPI_T_VERBOSITY_MPIDEV_DETAIL,
    PMPI_T_VERBOSITY_MPIDEV_ALL
} MPIR_T_verbosity_t;

typedef enum MPIR_T_bind_t {
    /* don't name-shift this if/when PMPI_T_ is accepted, this is an MPICH-only
     * extension */
    PMPI_T_BIND_INVALID = 0,

    /* arbitrarily shift values to aid debugging and reduce accidental errors */
    PMPI_T_BIND_NO_OBJECT = 9700,
    PMPI_T_BIND_MPI_COMM,
    PMPI_T_BIND_MPI_DATATYPE,
    PMPI_T_BIND_MPI_ERRHANDLER,
    PMPI_T_BIND_MPI_FILE,
    PMPI_T_BIND_MPI_GROUP,
    PMPI_T_BIND_MPI_OP,
    PMPI_T_BIND_MPI_REQUEST,
    PMPI_T_BIND_MPI_WIN,
    PMPI_T_BIND_MPI_MESSAGE,
    PMPI_T_BIND_MPI_INFO
} MPIR_T_bind_t;

typedef enum MPIR_T_scope_t {
    /* don't name-shift this if/when PMPI_T_ is accepted, this is an MPICH-only
     * extension */
    PMPI_T_SCOPE_INVALID = 0,

    /* arbitrarily shift values to aid debugging and reduce accidental errors */
    PMPI_T_SCOPE_CONSTANT = 60438,
    PMPI_T_SCOPE_READONLY,
    PMPI_T_SCOPE_LOCAL,
    PMPI_T_SCOPE_GROUP,
    PMPI_T_SCOPE_GROUP_EQ,
    PMPI_T_SCOPE_ALL,
    PMPI_T_SCOPE_ALL_EQ
} MPIR_T_scope_t;

typedef enum MPIR_T_pvar_class_t {
    /* don't name-shift this if/when PMPI_T_ is accepted, this is an MPICH-only
     * extension */
    PMPI_T_PVAR_CLASS_INVALID = 0,

    /* arbitrarily shift values to aid debugging and reduce accidental errors */
    MPIR_T_PVAR_CLASS_FIRST = 240,
    PMPI_T_PVAR_CLASS_STATE = MPIR_T_PVAR_CLASS_FIRST,
    PMPI_T_PVAR_CLASS_LEVEL,
    PMPI_T_PVAR_CLASS_SIZE,
    PMPI_T_PVAR_CLASS_PERCENTAGE,
    PMPI_T_PVAR_CLASS_HIGHWATERMARK,
    PMPI_T_PVAR_CLASS_LOWWATERMARK,
    PMPI_T_PVAR_CLASS_COUNTER,
    PMPI_T_PVAR_CLASS_AGGREGATE,
    PMPI_T_PVAR_CLASS_TIMER,
    PMPI_T_PVAR_CLASS_GENERIC,
    MPIR_T_PVAR_CLASS_LAST,
    MPIR_T_PVAR_CLASS_NUMBER = MPIR_T_PVAR_CLASS_LAST - MPIR_T_PVAR_CLASS_FIRST
} MPIR_T_pvar_class_t;

typedef enum PMPI_T_cb_safety {
    PMPI_T_CB_REQUIRE_NONE = 0,
    PMPI_T_CB_REQUIRE_MPI_RESTRICTED,
    PMPI_T_CB_REQUIRE_THREAD_SAFE,
    PMPI_T_CB_REQUIRE_ASYNC_SIGNAL_SAFE
} PMPI_T_cb_safety;

typedef enum PMPI_T_source_order {
    PMPI_T_SOURCE_ORDERED = 0,
    PMPI_T_SOURCE_UNORDERED
} PMPI_T_source_order;

typedef void (PMPI_T_event_cb_function)(PMPI_T_event_instance event_instance, PMPI_T_event_registration event_registration, PMPI_T_cb_safety cb_safety, void *user_data);
typedef void (PMPI_T_event_free_cb_function)(PMPI_T_event_registration event_registration, PMPI_T_cb_safety cb_safety, void *user_data);
typedef void (PMPI_T_event_dropped_cb_function)(PMPI_Count count, PMPI_T_event_registration event_registration, int source_index, PMPI_T_cb_safety cb_safety, void *user_data);

/* Handle conversion types/functions */

/* Programs that need to convert types used in MPICH should use these */
#define PMPI_Comm_c2f(comm) (PMPI_Fint)(comm)
#define PMPI_Comm_f2c(comm) (PMPI_Comm)(comm)
#define PMPI_Type_c2f(datatype) (PMPI_Fint)(datatype)
#define PMPI_Type_f2c(datatype) (PMPI_Datatype)(datatype)
#define PMPI_Group_c2f(group) (PMPI_Fint)(group)
#define PMPI_Group_f2c(group) (PMPI_Group)(group)
#define PMPI_Info_c2f(info) (PMPI_Fint)(info)
#define PMPI_Info_f2c(info) (PMPI_Info)(info)
#define PMPI_Request_f2c(request) (PMPI_Request)(request)
#define PMPI_Request_c2f(request) (PMPI_Fint)(request)
#define PMPI_Op_c2f(op) (PMPI_Fint)(op)
#define PMPI_Op_f2c(op) (PMPI_Op)(op)
#define PMPI_Errhandler_c2f(errhandler) (PMPI_Fint)(errhandler)
#define PMPI_Errhandler_f2c(errhandler) (PMPI_Errhandler)(errhandler)
#define PMPI_Win_c2f(win)   (PMPI_Fint)(win)
#define PMPI_Win_f2c(win)   (PMPI_Win)(win)
#define PMPI_Message_c2f(msg) ((PMPI_Fint)(msg))
#define PMPI_Message_f2c(msg) ((PMPI_Message)(msg))
#define PMPI_Session_c2f(session) (PMPI_Fint)(session)
#define PMPI_Session_f2c(session) (PMPI_Session)(session)

/* PMPI versions of the handle transfer functions.  See section 4.17 */
#define PMPI_Comm_c2f(comm) (PMPI_Fint)(comm)
#define PMPI_Comm_f2c(comm) (PMPI_Comm)(comm)
#define PMPI_Type_c2f(datatype) (PMPI_Fint)(datatype)
#define PMPI_Type_f2c(datatype) (PMPI_Datatype)(datatype)
#define PMPI_Group_c2f(group) (PMPI_Fint)(group)
#define PMPI_Group_f2c(group) (PMPI_Group)(group)
#define PMPI_Info_c2f(info) (PMPI_Fint)(info)
#define PMPI_Info_f2c(info) (PMPI_Info)(info)
#define PMPI_Request_f2c(request) (PMPI_Request)(request)
#define PMPI_Request_c2f(request) (PMPI_Fint)(request)
#define PMPI_Op_c2f(op) (PMPI_Fint)(op)
#define PMPI_Op_f2c(op) (PMPI_Op)(op)
#define PMPI_Errhandler_c2f(errhandler) (PMPI_Fint)(errhandler)
#define PMPI_Errhandler_f2c(errhandler) (PMPI_Errhandler)(errhandler)
#define PMPI_Win_c2f(win)   (PMPI_Fint)(win)
#define PMPI_Win_f2c(win)   (PMPI_Win)(win)
#define PMPI_Message_c2f(msg) ((PMPI_Fint)(msg))
#define PMPI_Message_f2c(msg) ((PMPI_Message)(msg))
#define PMPI_Session_c2f(session) (PMPI_Fint)(session)
#define PMPI_Session_f2c(session) (PMPI_Session)(session)

#define PMPI_STATUS_IGNORE (PMPI_Status *)1
#define PMPI_STATUSES_IGNORE (PMPI_Status *)1
#define PMPI_ERRCODES_IGNORE (int *)0

/* See 4.12.5 for PMPI_F_STATUS(ES)_IGNORE */
#define MPIU_DLL_SPEC
extern MPIU_DLL_SPEC PMPI_Fint * PMPI_F_STATUS_IGNORE;
extern MPIU_DLL_SPEC PMPI_Fint * PMPI_F_STATUSES_IGNORE;
/* The annotation MPIU_DLL_SPEC to the extern statements is used 
   as a hook for systems that require C extensions to correctly construct
   DLLs, and is defined as an empty string otherwise
 */

/* The MPI standard requires that the ARGV_NULL values be the same as
   NULL (see 5.3.2) */
#define PMPI_ARGV_NULL (char **)0
#define PMPI_ARGVS_NULL (char ***)0

/* C type for PMPI_STATUS in F08.
   The field order should match that in mpi_f08_types.f90, and mpi_c_interface_types.f90.
 */
typedef struct {
    PMPI_Fint count_lo;
    PMPI_Fint count_hi_and_cancelled;
    PMPI_Fint PMPI_SOURCE;
    PMPI_Fint PMPI_TAG;
    PMPI_Fint PMPI_ERROR;
} PMPI_F08_status;

/* MPI 4 added following constants to allow access F90 STATUS as an array of PMPI_Fint */
#define PMPI_F_STATUS_SIZE 5
#define PMPI_F_SOURCE 2
#define PMPI_F_TAG 3
#define PMPI_F_ERROR 4

/* Provided in libmpifort.so */
extern PMPI_F08_status *PMPI_F08_STATUS_IGNORE;
extern PMPI_F08_status *PMPI_F08_STATUSES_IGNORE;

/* For supported thread levels */
#define PMPI_THREAD_SINGLE 0
#define PMPI_THREAD_FUNNELED 1
#define PMPI_THREAD_SERIALIZED 2
#define PMPI_THREAD_MULTIPLE 3

/* Typedefs for generalized requests */
typedef int (PMPI_Grequest_cancel_function)(void *, int); 
typedef int (PMPI_Grequest_free_function)(void *); 
typedef int (PMPI_Grequest_query_function)(void *, PMPI_Status *); 
typedef int (PMPIX_Grequest_poll_function)(void *, PMPI_Status *);
typedef int (PMPIX_Grequest_wait_function)(int, void **, double, PMPI_Status *);

/* MPI's error classes */
#define PMPI_SUCCESS          0      /* Successful return code */
/* Communication argument parameters */
#define PMPI_ERR_BUFFER       1      /* Invalid buffer pointer */
#define PMPI_ERR_COUNT        2      /* Invalid count argument */
#define PMPI_ERR_TYPE         3      /* Invalid datatype argument */
#define PMPI_ERR_TAG          4      /* Invalid tag argument */
#define PMPI_ERR_COMM         5      /* Invalid communicator */
#define PMPI_ERR_RANK         6      /* Invalid rank */
#define PMPI_ERR_ROOT         7      /* Invalid root */
#define PMPI_ERR_TRUNCATE    14      /* Message truncated on receive */

/* MPI Objects (other than COMM) */
#define PMPI_ERR_GROUP        8      /* Invalid group */
#define PMPI_ERR_OP           9      /* Invalid operation */
#define PMPI_ERR_REQUEST     19      /* Invalid mpi_request handle */

/* Special topology argument parameters */
#define PMPI_ERR_TOPOLOGY    10      /* Invalid topology */
#define PMPI_ERR_DIMS        11      /* Invalid dimension argument */

/* All other arguments.  This is a class with many kinds */
#define PMPI_ERR_ARG         12      /* Invalid argument */

/* Other errors that are not simply an invalid argument */
#define PMPI_ERR_OTHER       15      /* Other error; use Error_string */

#define PMPI_ERR_UNKNOWN     13      /* Unknown error */
#define PMPI_ERR_INTERN      16      /* Internal error code    */

/* Multiple completion has three special error classes */
#define PMPI_ERR_IN_STATUS           17      /* Look in status for error value */
#define PMPI_ERR_PENDING             18      /* Pending request */

/* New MPI-2 Error classes */
#define PMPI_ERR_ACCESS      20      /* */
#define PMPI_ERR_AMODE       21      /* */
#define PMPI_ERR_BAD_FILE    22      /* */
#define PMPI_ERR_CONVERSION  23      /* */
#define PMPI_ERR_DUP_DATAREP 24      /* */
#define PMPI_ERR_FILE_EXISTS 25      /* */
#define PMPI_ERR_FILE_IN_USE 26      /* */
#define PMPI_ERR_FILE        27      /* */
#define PMPI_ERR_IO          32      /* */
#define PMPI_ERR_NO_SPACE    36      /* */
#define PMPI_ERR_NO_SUCH_FILE 37     /* */
#define PMPI_ERR_READ_ONLY   40      /* */
#define PMPI_ERR_UNSUPPORTED_DATAREP   43  /* */

/* PMPI_ERR_INFO is NOT defined in the MPI-2 standard.  I believe that
   this is an oversight */
#define PMPI_ERR_INFO        28      /* */
#define PMPI_ERR_INFO_KEY    29      /* */
#define PMPI_ERR_INFO_VALUE  30      /* */
#define PMPI_ERR_INFO_NOKEY  31      /* */

#define PMPI_ERR_NAME        33      /* */
#define PMPI_ERR_NO_MEM      34      /* Alloc_mem could not allocate memory */
#define PMPI_ERR_NOT_SAME    35      /* */
#define PMPI_ERR_PORT        38      /* */
#define PMPI_ERR_QUOTA       39      /* */
#define PMPI_ERR_SERVICE     41      /* */
#define PMPI_ERR_SPAWN       42      /* */
#define PMPI_ERR_UNSUPPORTED_OPERATION 44 /* */
#define PMPI_ERR_WIN         45      /* */

#define PMPI_ERR_BASE        46      /* */
#define PMPI_ERR_LOCKTYPE    47      /* */
#define PMPI_ERR_KEYVAL      48      /* Erroneous attribute key */
#define PMPI_ERR_RMA_CONFLICT 49     /* */
#define PMPI_ERR_RMA_SYNC    50      /* */ 
#define PMPI_ERR_SIZE        51      /* */
#define PMPI_ERR_DISP        52      /* */
#define PMPI_ERR_ASSERT      53      /* */

#define PMPI_ERR_RMA_RANGE  55       /* */
#define PMPI_ERR_RMA_ATTACH 56       /* */
#define PMPI_ERR_RMA_SHARED 57       /* */
#define PMPI_ERR_RMA_FLAVOR 58       /* */

/* Return codes for functions in the MPI Tool Information Interface */
#define PMPI_T_ERR_MEMORY            59  /* Out of memory */
#define PMPI_T_ERR_NOT_INITIALIZED   60  /* Interface not initialized */
#define PMPI_T_ERR_CANNOT_INIT       61  /* Interface not in the state to
                                           be initialized */
#define PMPI_T_ERR_INVALID_INDEX     62  /* The index is invalid or
                                           has been deleted  */
#define PMPI_T_ERR_INVALID_ITEM      63  /* Deprecated.  If a queried item index is out of range,
                                         * MPI-4 will return PMPI_T_ERR_INVALID_INDEX instead. */
#define PMPI_T_ERR_INVALID_HANDLE    64  /* The handle is invalid */
#define PMPI_T_ERR_OUT_OF_HANDLES    65  /* No more handles available */
#define PMPI_T_ERR_OUT_OF_SESSIONS   66  /* No more sessions available */
#define PMPI_T_ERR_INVALID_SESSION   67  /* Session argument is not valid */
#define PMPI_T_ERR_CVAR_SET_NOT_NOW  68  /* Cvar can't be set at this moment */
#define PMPI_T_ERR_CVAR_SET_NEVER    69  /* Cvar can't be set until
                                           end of execution */
#define PMPI_T_ERR_PVAR_NO_STARTSTOP 70  /* Pvar can't be started or stopped */
#define PMPI_T_ERR_PVAR_NO_WRITE     71  /* Pvar can't be written or reset */
#define PMPI_T_ERR_PVAR_NO_ATOMIC    72  /* Pvar can't be R/W atomically */
#define PMPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */
#define PMPI_T_ERR_INVALID           74  /* Generic error code for PMPI_T added in MPI-3.1 */

#define PMPI_ERR_SESSION            75  /* Invalid session handle */
#define PMPI_ERR_PROC_ABORTED       76  /* Trying to communicate with aborted processes */
#define PMPI_ERR_VALUE_TOO_LARGE    77  /* Value is too large to store */

#define PMPI_T_ERR_NOT_SUPPORTED    78  /* Requested functionality not supported */

#define PMPI_ERR_LASTCODE    0x3fffffff  /* Last valid error code for a 
					   predefined error class */
#define MPICH_ERR_LAST_CLASS 78     /* It is also helpful to know the
				       last valid class */

#define MPICH_ERR_FIRST_MPIX 100 /* Define a gap here because sock is
                                  * already using some of the values in this
                                  * range. All MPIX error codes will be
                                  * above this value to be ABI complaint. */

#define PMPIX_ERR_PROC_FAILED          MPICH_ERR_FIRST_MPIX+1 /* Process failure */
#define PMPIX_ERR_PROC_FAILED_PENDING  MPICH_ERR_FIRST_MPIX+2 /* A failure has caused this request
                                                              * to be pending */
#define PMPIX_ERR_REVOKED              MPICH_ERR_FIRST_MPIX+3 /* The communication object has been revoked */
#define PMPIX_ERR_EAGAIN               MPICH_ERR_FIRST_MPIX+4 /* Operation could not be issued */
#define PMPIX_ERR_NOREQ                MPICH_ERR_FIRST_MPIX+5 /* Cannot allocate request */
#define PMPIX_ERR_STREAM               MPICH_ERR_FIRST_MPIX+6 /* Invalid stream */
#define PMPIX_ERR_TIMEOUT              MPICH_ERR_FIRST_MPIX+7 /* Operation timed out */

#define MPICH_ERR_LAST_MPIX           MPICH_ERR_FIRST_MPIX+7


/* End of MPI's error classes */

/* Function type defs */
typedef int (PMPI_Datarep_conversion_function)(void *, PMPI_Datatype, int, 
             void *, PMPI_Offset, void *);
typedef int (PMPI_Datarep_extent_function)(PMPI_Datatype datatype, PMPI_Aint *,
                      void *);
#define PMPI_CONVERSION_FN_NULL ((PMPI_Datarep_conversion_function *)0)

typedef int (PMPI_Datarep_conversion_function_c)(void *, PMPI_Datatype, PMPI_Count,
             void *, PMPI_Offset, void *);
#define PMPI_CONVERSION_FN_NULL_C ((PMPI_Datarep_conversion_function_c *)0)

/* same as struct iovec, provided to avoid header dependency */
typedef struct PMPIX_Iov {
    void *iov_base;
    PMPI_Aint iov_len;
} PMPIX_Iov;

#include "pmpi_proto.h"

/* GPU extensions */
#define PMPIX_GPU_SUPPORT_CUDA  (0)
#define PMPIX_GPU_SUPPORT_ZE    (1)
#define PMPIX_GPU_SUPPORT_HIP   (2)

/* feature advertisement */
#define MPIIMPL_ADVERTISES_FEATURES 1
#define MPIIMPL_HAVE_MPI_INFO 1                                                 
#define MPIIMPL_HAVE_MPI_COMBINER_DARRAY 1                                      
#define MPIIMPL_HAVE_MPI_TYPE_CREATE_DARRAY 1
#define MPIIMPL_HAVE_MPI_COMBINER_SUBARRAY 1                                    
#define MPIIMPL_HAVE_MPI_TYPE_CREATE_DARRAY 1
#define MPIIMPL_HAVE_MPI_COMBINER_DUP 1                                         
#define MPIIMPL_HAVE_MPI_GREQUEST 1      
#define MPIIMPL_HAVE_STATUS_SET_BYTES 1
#define MPIIMPL_HAVE_STATUS_SET_INFO 1



#if defined(__cplusplus)
}
/* Add the C++ bindings */
/* 
   If MPICH_SKIP_MPICXX is defined, the mpicxx.h file will *not* be included.
   This is necessary, for example, when building the C++ interfaces.  It
   can also be used when you want to use a C++ compiler to compile C code,
   and do not want to load the C++ bindings.  These definitions can
   be made by the C++ compilation script
 */
#if !defined(MPICH_SKIP_MPICXX)
/* mpicxx.h contains the MPI C++ binding.  In the mpi.h.in file, this 
   include is in an autoconf variable in case the compiler is a C++ 
   compiler but MPI was built without the C++ bindings */

#endif 
#endif

#endif
