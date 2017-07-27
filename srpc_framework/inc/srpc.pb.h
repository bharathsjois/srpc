// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: srpc.proto

#ifndef PROTOBUF_srpc_2eproto__INCLUDED
#define PROTOBUF_srpc_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3002000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3002000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace srpc {
namespace types {
class SrpcMessageHeader;
class SrpcMessageHeaderDefaultTypeInternal;
extern SrpcMessageHeaderDefaultTypeInternal _SrpcMessageHeader_default_instance_;
class SrpcString;
class SrpcStringDefaultTypeInternal;
extern SrpcStringDefaultTypeInternal _SrpcString_default_instance_;
class SrpcStringList;
class SrpcStringListDefaultTypeInternal;
extern SrpcStringListDefaultTypeInternal _SrpcStringList_default_instance_;
}  // namespace types
}  // namespace srpc

namespace srpc {
namespace types {

namespace protobuf_srpc_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_srpc_2eproto

enum SrpcMessageHeader_MessageType {
  SrpcMessageHeader_MessageType_UNKNOWN = 0,
  SrpcMessageHeader_MessageType_METHOD = 1,
  SrpcMessageHeader_MessageType_RESULT = 2,
  SrpcMessageHeader_MessageType_SIGNAL = 3,
  SrpcMessageHeader_MessageType_SrpcMessageHeader_MessageType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SrpcMessageHeader_MessageType_SrpcMessageHeader_MessageType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SrpcMessageHeader_MessageType_IsValid(int value);
const SrpcMessageHeader_MessageType SrpcMessageHeader_MessageType_MessageType_MIN = SrpcMessageHeader_MessageType_UNKNOWN;
const SrpcMessageHeader_MessageType SrpcMessageHeader_MessageType_MessageType_MAX = SrpcMessageHeader_MessageType_SIGNAL;
const int SrpcMessageHeader_MessageType_MessageType_ARRAYSIZE = SrpcMessageHeader_MessageType_MessageType_MAX + 1;

const ::google::protobuf::EnumDescriptor* SrpcMessageHeader_MessageType_descriptor();
inline const ::std::string& SrpcMessageHeader_MessageType_Name(SrpcMessageHeader_MessageType value) {
  return ::google::protobuf::internal::NameOfEnum(
    SrpcMessageHeader_MessageType_descriptor(), value);
}
inline bool SrpcMessageHeader_MessageType_Parse(
    const ::std::string& name, SrpcMessageHeader_MessageType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SrpcMessageHeader_MessageType>(
    SrpcMessageHeader_MessageType_descriptor(), name, value);
}
enum SrpcMessageHeader_MessageNature {
  SrpcMessageHeader_MessageNature_DEFAULT = 0,
  SrpcMessageHeader_MessageNature_SYNC = 1,
  SrpcMessageHeader_MessageNature_ASYNC = 2,
  SrpcMessageHeader_MessageNature_SrpcMessageHeader_MessageNature_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SrpcMessageHeader_MessageNature_SrpcMessageHeader_MessageNature_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SrpcMessageHeader_MessageNature_IsValid(int value);
const SrpcMessageHeader_MessageNature SrpcMessageHeader_MessageNature_MessageNature_MIN = SrpcMessageHeader_MessageNature_DEFAULT;
const SrpcMessageHeader_MessageNature SrpcMessageHeader_MessageNature_MessageNature_MAX = SrpcMessageHeader_MessageNature_ASYNC;
const int SrpcMessageHeader_MessageNature_MessageNature_ARRAYSIZE = SrpcMessageHeader_MessageNature_MessageNature_MAX + 1;

const ::google::protobuf::EnumDescriptor* SrpcMessageHeader_MessageNature_descriptor();
inline const ::std::string& SrpcMessageHeader_MessageNature_Name(SrpcMessageHeader_MessageNature value) {
  return ::google::protobuf::internal::NameOfEnum(
    SrpcMessageHeader_MessageNature_descriptor(), value);
}
inline bool SrpcMessageHeader_MessageNature_Parse(
    const ::std::string& name, SrpcMessageHeader_MessageNature* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SrpcMessageHeader_MessageNature>(
    SrpcMessageHeader_MessageNature_descriptor(), name, value);
}
// ===================================================================

class SrpcMessageHeader : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:srpc.types.SrpcMessageHeader) */ {
 public:
  SrpcMessageHeader();
  virtual ~SrpcMessageHeader();

  SrpcMessageHeader(const SrpcMessageHeader& from);

  inline SrpcMessageHeader& operator=(const SrpcMessageHeader& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SrpcMessageHeader& default_instance();

  static inline const SrpcMessageHeader* internal_default_instance() {
    return reinterpret_cast<const SrpcMessageHeader*>(
               &_SrpcMessageHeader_default_instance_);
  }

  void Swap(SrpcMessageHeader* other);

  // implements Message ----------------------------------------------

  inline SrpcMessageHeader* New() const PROTOBUF_FINAL { return New(NULL); }

  SrpcMessageHeader* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SrpcMessageHeader& from);
  void MergeFrom(const SrpcMessageHeader& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SrpcMessageHeader* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef SrpcMessageHeader_MessageType MessageType;
  static const MessageType UNKNOWN =
    SrpcMessageHeader_MessageType_UNKNOWN;
  static const MessageType METHOD =
    SrpcMessageHeader_MessageType_METHOD;
  static const MessageType RESULT =
    SrpcMessageHeader_MessageType_RESULT;
  static const MessageType SIGNAL =
    SrpcMessageHeader_MessageType_SIGNAL;
  static inline bool MessageType_IsValid(int value) {
    return SrpcMessageHeader_MessageType_IsValid(value);
  }
  static const MessageType MessageType_MIN =
    SrpcMessageHeader_MessageType_MessageType_MIN;
  static const MessageType MessageType_MAX =
    SrpcMessageHeader_MessageType_MessageType_MAX;
  static const int MessageType_ARRAYSIZE =
    SrpcMessageHeader_MessageType_MessageType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  MessageType_descriptor() {
    return SrpcMessageHeader_MessageType_descriptor();
  }
  static inline const ::std::string& MessageType_Name(MessageType value) {
    return SrpcMessageHeader_MessageType_Name(value);
  }
  static inline bool MessageType_Parse(const ::std::string& name,
      MessageType* value) {
    return SrpcMessageHeader_MessageType_Parse(name, value);
  }

  typedef SrpcMessageHeader_MessageNature MessageNature;
  static const MessageNature DEFAULT =
    SrpcMessageHeader_MessageNature_DEFAULT;
  static const MessageNature SYNC =
    SrpcMessageHeader_MessageNature_SYNC;
  static const MessageNature ASYNC =
    SrpcMessageHeader_MessageNature_ASYNC;
  static inline bool MessageNature_IsValid(int value) {
    return SrpcMessageHeader_MessageNature_IsValid(value);
  }
  static const MessageNature MessageNature_MIN =
    SrpcMessageHeader_MessageNature_MessageNature_MIN;
  static const MessageNature MessageNature_MAX =
    SrpcMessageHeader_MessageNature_MessageNature_MAX;
  static const int MessageNature_ARRAYSIZE =
    SrpcMessageHeader_MessageNature_MessageNature_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  MessageNature_descriptor() {
    return SrpcMessageHeader_MessageNature_descriptor();
  }
  static inline const ::std::string& MessageNature_Name(MessageNature value) {
    return SrpcMessageHeader_MessageNature_Name(value);
  }
  static inline bool MessageNature_Parse(const ::std::string& name,
      MessageNature* value) {
    return SrpcMessageHeader_MessageNature_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // .srpc.types.SrpcMessageHeader.MessageType type = 1;
  void clear_type();
  static const int kTypeFieldNumber = 1;
  ::srpc::types::SrpcMessageHeader_MessageType type() const;
  void set_type(::srpc::types::SrpcMessageHeader_MessageType value);

  // int32 mid = 2;
  void clear_mid();
  static const int kMidFieldNumber = 2;
  ::google::protobuf::int32 mid() const;
  void set_mid(::google::protobuf::int32 value);

  // int32 rid = 3;
  void clear_rid();
  static const int kRidFieldNumber = 3;
  ::google::protobuf::int32 rid() const;
  void set_rid(::google::protobuf::int32 value);

  // .srpc.types.SrpcMessageHeader.MessageNature nature = 4;
  void clear_nature();
  static const int kNatureFieldNumber = 4;
  ::srpc::types::SrpcMessageHeader_MessageNature nature() const;
  void set_nature(::srpc::types::SrpcMessageHeader_MessageNature value);

  // @@protoc_insertion_point(class_scope:srpc.types.SrpcMessageHeader)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  int type_;
  ::google::protobuf::int32 mid_;
  ::google::protobuf::int32 rid_;
  int nature_;
  mutable int _cached_size_;
  friend struct protobuf_srpc_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SrpcString : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:srpc.types.SrpcString) */ {
 public:
  SrpcString();
  virtual ~SrpcString();

  SrpcString(const SrpcString& from);

  inline SrpcString& operator=(const SrpcString& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SrpcString& default_instance();

  static inline const SrpcString* internal_default_instance() {
    return reinterpret_cast<const SrpcString*>(
               &_SrpcString_default_instance_);
  }

  void Swap(SrpcString* other);

  // implements Message ----------------------------------------------

  inline SrpcString* New() const PROTOBUF_FINAL { return New(NULL); }

  SrpcString* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SrpcString& from);
  void MergeFrom(const SrpcString& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SrpcString* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string string = 1;
  void clear_string();
  static const int kStringFieldNumber = 1;
  const ::std::string& string() const;
  void set_string(const ::std::string& value);
  #if LANG_CXX11
  void set_string(::std::string&& value);
  #endif
  void set_string(const char* value);
  void set_string(const char* value, size_t size);
  ::std::string* mutable_string();
  ::std::string* release_string();
  void set_allocated_string(::std::string* string);

  // @@protoc_insertion_point(class_scope:srpc.types.SrpcString)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr string_;
  mutable int _cached_size_;
  friend struct protobuf_srpc_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SrpcStringList : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:srpc.types.SrpcStringList) */ {
 public:
  SrpcStringList();
  virtual ~SrpcStringList();

  SrpcStringList(const SrpcStringList& from);

  inline SrpcStringList& operator=(const SrpcStringList& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SrpcStringList& default_instance();

  static inline const SrpcStringList* internal_default_instance() {
    return reinterpret_cast<const SrpcStringList*>(
               &_SrpcStringList_default_instance_);
  }

  void Swap(SrpcStringList* other);

  // implements Message ----------------------------------------------

  inline SrpcStringList* New() const PROTOBUF_FINAL { return New(NULL); }

  SrpcStringList* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SrpcStringList& from);
  void MergeFrom(const SrpcStringList& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(SrpcStringList* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated string string = 1;
  int string_size() const;
  void clear_string();
  static const int kStringFieldNumber = 1;
  const ::std::string& string(int index) const;
  ::std::string* mutable_string(int index);
  void set_string(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_string(int index, ::std::string&& value);
  #endif
  void set_string(int index, const char* value);
  void set_string(int index, const char* value, size_t size);
  ::std::string* add_string();
  void add_string(const ::std::string& value);
  #if LANG_CXX11
  void add_string(::std::string&& value);
  #endif
  void add_string(const char* value);
  void add_string(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& string() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_string();

  // @@protoc_insertion_point(class_scope:srpc.types.SrpcStringList)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::std::string> string_;
  mutable int _cached_size_;
  friend struct protobuf_srpc_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// SrpcMessageHeader

// .srpc.types.SrpcMessageHeader.MessageType type = 1;
inline void SrpcMessageHeader::clear_type() {
  type_ = 0;
}
inline ::srpc::types::SrpcMessageHeader_MessageType SrpcMessageHeader::type() const {
  // @@protoc_insertion_point(field_get:srpc.types.SrpcMessageHeader.type)
  return static_cast< ::srpc::types::SrpcMessageHeader_MessageType >(type_);
}
inline void SrpcMessageHeader::set_type(::srpc::types::SrpcMessageHeader_MessageType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:srpc.types.SrpcMessageHeader.type)
}

// int32 mid = 2;
inline void SrpcMessageHeader::clear_mid() {
  mid_ = 0;
}
inline ::google::protobuf::int32 SrpcMessageHeader::mid() const {
  // @@protoc_insertion_point(field_get:srpc.types.SrpcMessageHeader.mid)
  return mid_;
}
inline void SrpcMessageHeader::set_mid(::google::protobuf::int32 value) {
  
  mid_ = value;
  // @@protoc_insertion_point(field_set:srpc.types.SrpcMessageHeader.mid)
}

// int32 rid = 3;
inline void SrpcMessageHeader::clear_rid() {
  rid_ = 0;
}
inline ::google::protobuf::int32 SrpcMessageHeader::rid() const {
  // @@protoc_insertion_point(field_get:srpc.types.SrpcMessageHeader.rid)
  return rid_;
}
inline void SrpcMessageHeader::set_rid(::google::protobuf::int32 value) {
  
  rid_ = value;
  // @@protoc_insertion_point(field_set:srpc.types.SrpcMessageHeader.rid)
}

// .srpc.types.SrpcMessageHeader.MessageNature nature = 4;
inline void SrpcMessageHeader::clear_nature() {
  nature_ = 0;
}
inline ::srpc::types::SrpcMessageHeader_MessageNature SrpcMessageHeader::nature() const {
  // @@protoc_insertion_point(field_get:srpc.types.SrpcMessageHeader.nature)
  return static_cast< ::srpc::types::SrpcMessageHeader_MessageNature >(nature_);
}
inline void SrpcMessageHeader::set_nature(::srpc::types::SrpcMessageHeader_MessageNature value) {
  
  nature_ = value;
  // @@protoc_insertion_point(field_set:srpc.types.SrpcMessageHeader.nature)
}

// -------------------------------------------------------------------

// SrpcString

// string string = 1;
inline void SrpcString::clear_string() {
  string_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SrpcString::string() const {
  // @@protoc_insertion_point(field_get:srpc.types.SrpcString.string)
  return string_.GetNoArena();
}
inline void SrpcString::set_string(const ::std::string& value) {
  
  string_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:srpc.types.SrpcString.string)
}
#if LANG_CXX11
inline void SrpcString::set_string(::std::string&& value) {
  
  string_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:srpc.types.SrpcString.string)
}
#endif
inline void SrpcString::set_string(const char* value) {
  
  string_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:srpc.types.SrpcString.string)
}
inline void SrpcString::set_string(const char* value, size_t size) {
  
  string_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:srpc.types.SrpcString.string)
}
inline ::std::string* SrpcString::mutable_string() {
  
  // @@protoc_insertion_point(field_mutable:srpc.types.SrpcString.string)
  return string_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SrpcString::release_string() {
  // @@protoc_insertion_point(field_release:srpc.types.SrpcString.string)
  
  return string_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SrpcString::set_allocated_string(::std::string* string) {
  if (string != NULL) {
    
  } else {
    
  }
  string_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), string);
  // @@protoc_insertion_point(field_set_allocated:srpc.types.SrpcString.string)
}

// -------------------------------------------------------------------

// SrpcStringList

// repeated string string = 1;
inline int SrpcStringList::string_size() const {
  return string_.size();
}
inline void SrpcStringList::clear_string() {
  string_.Clear();
}
inline const ::std::string& SrpcStringList::string(int index) const {
  // @@protoc_insertion_point(field_get:srpc.types.SrpcStringList.string)
  return string_.Get(index);
}
inline ::std::string* SrpcStringList::mutable_string(int index) {
  // @@protoc_insertion_point(field_mutable:srpc.types.SrpcStringList.string)
  return string_.Mutable(index);
}
inline void SrpcStringList::set_string(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:srpc.types.SrpcStringList.string)
  string_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void SrpcStringList::set_string(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:srpc.types.SrpcStringList.string)
  string_.Mutable(index)->assign(std::move(value));
}
#endif
inline void SrpcStringList::set_string(int index, const char* value) {
  string_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:srpc.types.SrpcStringList.string)
}
inline void SrpcStringList::set_string(int index, const char* value, size_t size) {
  string_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:srpc.types.SrpcStringList.string)
}
inline ::std::string* SrpcStringList::add_string() {
  // @@protoc_insertion_point(field_add_mutable:srpc.types.SrpcStringList.string)
  return string_.Add();
}
inline void SrpcStringList::add_string(const ::std::string& value) {
  string_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:srpc.types.SrpcStringList.string)
}
#if LANG_CXX11
inline void SrpcStringList::add_string(::std::string&& value) {
  string_.Add()->assign(std::move(value));
  // @@protoc_insertion_point(field_add:srpc.types.SrpcStringList.string)
}
#endif
inline void SrpcStringList::add_string(const char* value) {
  string_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:srpc.types.SrpcStringList.string)
}
inline void SrpcStringList::add_string(const char* value, size_t size) {
  string_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:srpc.types.SrpcStringList.string)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
SrpcStringList::string() const {
  // @@protoc_insertion_point(field_list:srpc.types.SrpcStringList.string)
  return string_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
SrpcStringList::mutable_string() {
  // @@protoc_insertion_point(field_mutable_list:srpc.types.SrpcStringList.string)
  return &string_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace types
}  // namespace srpc

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::srpc::types::SrpcMessageHeader_MessageType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::srpc::types::SrpcMessageHeader_MessageType>() {
  return ::srpc::types::SrpcMessageHeader_MessageType_descriptor();
}
template <> struct is_proto_enum< ::srpc::types::SrpcMessageHeader_MessageNature> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::srpc::types::SrpcMessageHeader_MessageNature>() {
  return ::srpc::types::SrpcMessageHeader_MessageNature_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_srpc_2eproto__INCLUDED