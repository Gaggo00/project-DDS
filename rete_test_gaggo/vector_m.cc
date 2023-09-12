//
// Generated file, do not edit! Created by opp_msgtool 6.0 from vector.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "vector_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(VectorMsg)

VectorMsg::VectorMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

VectorMsg::VectorMsg(const VectorMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

VectorMsg::~VectorMsg()
{
    delete [] this->vector;
}

VectorMsg& VectorMsg::operator=(const VectorMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void VectorMsg::copy(const VectorMsg& other)
{
    delete [] this->vector;
    this->vector = (other.vector_arraysize==0) ? nullptr : new int[other.vector_arraysize];
    vector_arraysize = other.vector_arraysize;
    for (size_t i = 0; i < vector_arraysize; i++) {
        this->vector[i] = other.vector[i];
    }
    this->sender = other.sender;
}

void VectorMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    b->pack(vector_arraysize);
    doParsimArrayPacking(b,this->vector,vector_arraysize);
    doParsimPacking(b,this->sender);
}

void VectorMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    delete [] this->vector;
    b->unpack(vector_arraysize);
    if (vector_arraysize == 0) {
        this->vector = nullptr;
    } else {
        this->vector = new int[vector_arraysize];
        doParsimArrayUnpacking(b,this->vector,vector_arraysize);
    }
    doParsimUnpacking(b,this->sender);
}

size_t VectorMsg::getVectorArraySize() const
{
    return vector_arraysize;
}

int VectorMsg::getVector(size_t k) const
{
    if (k >= vector_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)vector_arraysize, (unsigned long)k);
    return this->vector[k];
}

void VectorMsg::setVectorArraySize(size_t newSize)
{
    int *vector2 = (newSize==0) ? nullptr : new int[newSize];
    size_t minSize = vector_arraysize < newSize ? vector_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        vector2[i] = this->vector[i];
    for (size_t i = minSize; i < newSize; i++)
        vector2[i] = 0;
    delete [] this->vector;
    this->vector = vector2;
    vector_arraysize = newSize;
}

void VectorMsg::setVector(size_t k, int vector)
{
    if (k >= vector_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)vector_arraysize, (unsigned long)k);
    this->vector[k] = vector;
}

void VectorMsg::insertVector(size_t k, int vector)
{
    if (k > vector_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)vector_arraysize, (unsigned long)k);
    size_t newSize = vector_arraysize + 1;
    int *vector2 = new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        vector2[i] = this->vector[i];
    vector2[k] = vector;
    for (i = k + 1; i < newSize; i++)
        vector2[i] = this->vector[i-1];
    delete [] this->vector;
    this->vector = vector2;
    vector_arraysize = newSize;
}

void VectorMsg::appendVector(int vector)
{
    insertVector(vector_arraysize, vector);
}

void VectorMsg::eraseVector(size_t k)
{
    if (k >= vector_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)vector_arraysize, (unsigned long)k);
    size_t newSize = vector_arraysize - 1;
    int *vector2 = (newSize == 0) ? nullptr : new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        vector2[i] = this->vector[i];
    for (i = k; i < newSize; i++)
        vector2[i] = this->vector[i+1];
    delete [] this->vector;
    this->vector = vector2;
    vector_arraysize = newSize;
}

int VectorMsg::getSender() const
{
    return this->sender;
}

void VectorMsg::setSender(int sender)
{
    this->sender = sender;
}

class VectorMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_vector,
        FIELD_sender,
    };
  public:
    VectorMsgDescriptor();
    virtual ~VectorMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(VectorMsgDescriptor)

VectorMsgDescriptor::VectorMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(VectorMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

VectorMsgDescriptor::~VectorMsgDescriptor()
{
    delete[] propertyNames;
}

bool VectorMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<VectorMsg *>(obj)!=nullptr;
}

const char **VectorMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *VectorMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int VectorMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int VectorMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_vector
        FD_ISEDITABLE,    // FIELD_sender
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *VectorMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "vector",
        "sender",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int VectorMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "vector") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sender") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *VectorMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_vector
        "int",    // FIELD_sender
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **VectorMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *VectorMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int VectorMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    VectorMsg *pp = omnetpp::fromAnyPtr<VectorMsg>(object); (void)pp;
    switch (field) {
        case FIELD_vector: return pp->getVectorArraySize();
        default: return 0;
    }
}

void VectorMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    VectorMsg *pp = omnetpp::fromAnyPtr<VectorMsg>(object); (void)pp;
    switch (field) {
        case FIELD_vector: pp->setVectorArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'VectorMsg'", field);
    }
}

const char *VectorMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    VectorMsg *pp = omnetpp::fromAnyPtr<VectorMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string VectorMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    VectorMsg *pp = omnetpp::fromAnyPtr<VectorMsg>(object); (void)pp;
    switch (field) {
        case FIELD_vector: return long2string(pp->getVector(i));
        case FIELD_sender: return long2string(pp->getSender());
        default: return "";
    }
}

void VectorMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    VectorMsg *pp = omnetpp::fromAnyPtr<VectorMsg>(object); (void)pp;
    switch (field) {
        case FIELD_vector: pp->setVector(i,string2long(value)); break;
        case FIELD_sender: pp->setSender(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'VectorMsg'", field);
    }
}

omnetpp::cValue VectorMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    VectorMsg *pp = omnetpp::fromAnyPtr<VectorMsg>(object); (void)pp;
    switch (field) {
        case FIELD_vector: return pp->getVector(i);
        case FIELD_sender: return pp->getSender();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'VectorMsg' as cValue -- field index out of range?", field);
    }
}

void VectorMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    VectorMsg *pp = omnetpp::fromAnyPtr<VectorMsg>(object); (void)pp;
    switch (field) {
        case FIELD_vector: pp->setVector(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sender: pp->setSender(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'VectorMsg'", field);
    }
}

const char *VectorMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr VectorMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    VectorMsg *pp = omnetpp::fromAnyPtr<VectorMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void VectorMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    VectorMsg *pp = omnetpp::fromAnyPtr<VectorMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'VectorMsg'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp
