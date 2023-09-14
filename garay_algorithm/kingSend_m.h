//
// Generated file, do not edit! Created by opp_msgtool 6.0 from kingSend.msg.
//

#ifndef __KINGSEND_M_H
#define __KINGSEND_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class KingSend;
/**
 * Class generated from <tt>kingSend.msg:2</tt> by opp_msgtool.
 * <pre>
 * message KingSend
 * {
 *     int value;
 *     int sender;
 * }
 * </pre>
 */
class KingSend : public ::omnetpp::cMessage
{
  protected:
    int value = 0;
    int sender = 0;

  private:
    void copy(const KingSend& other);

  protected:
    bool operator==(const KingSend&) = delete;

  public:
    KingSend(const char *name=nullptr, short kind=0);
    KingSend(const KingSend& other);
    virtual ~KingSend();
    KingSend& operator=(const KingSend& other);
    virtual KingSend *dup() const override {return new KingSend(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getValue() const;
    virtual void setValue(int value);

    virtual int getSender() const;
    virtual void setSender(int sender);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const KingSend& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, KingSend& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline KingSend *fromAnyPtr(any_ptr ptr) { return check_and_cast<KingSend*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __KINGSEND_M_H

