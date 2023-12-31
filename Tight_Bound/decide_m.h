//
// Generated file, do not edit! Created by opp_msgtool 6.0 from decide.msg.
//

#ifndef __DECIDE_M_H
#define __DECIDE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class Decide;
/**
 * Class generated from <tt>decide.msg:1</tt> by opp_msgtool.
 * <pre>
 * message Decide
 * {
 *     int data[];
 *     int value;
 *     int sender;
 * 
 * 
 * }
 * </pre>
 */
class Decide : public ::omnetpp::cMessage
{
  protected:
    int *data = nullptr;
    size_t data_arraysize = 0;
    int value = 0;
    int sender = 0;

  private:
    void copy(const Decide& other);

  protected:
    bool operator==(const Decide&) = delete;

  public:
    Decide(const char *name=nullptr, short kind=0);
    Decide(const Decide& other);
    virtual ~Decide();
    Decide& operator=(const Decide& other);
    virtual Decide *dup() const override {return new Decide(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual void setDataArraySize(size_t size);
    virtual size_t getDataArraySize() const;
    virtual int getData(size_t k) const;
    virtual void setData(size_t k, int data);
    virtual void insertData(size_t k, int data);
    [[deprecated]] void insertData(int data) {appendData(data);}
    virtual void appendData(int data);
    virtual void eraseData(size_t k);

    virtual int getValue() const;
    virtual void setValue(int value);

    virtual int getSender() const;
    virtual void setSender(int sender);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Decide& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Decide& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline Decide *fromAnyPtr(any_ptr ptr) { return check_and_cast<Decide*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __DECIDE_M_H

