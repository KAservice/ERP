#ifndef UIDMQueryReadH
#define UIDMQueryReadH
#include "IMainInterface.h"

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBQuery.hpp"


class __declspec(uuid("{3A469C2E-0054-4AC7-860C-60D7B127A3B2}")) IDMQueryRead  : public IMainInterface
{
public:
   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TpFIBTransaction * pFIBTr = {read = get_pFIBTr , write = set_pFIBTr};
   virtual TpFIBTransaction * get_pFIBTr(void)=0;
   virtual void set_pFIBTr(TpFIBTransaction * pFIBTr)=0;

   __property TpFIBQuery * Query = {read = get_Query , write = set_Query};
   virtual TpFIBQuery * get_Query(void)=0;
   virtual void set_Query(TpFIBQuery * Query)=0;

   __property TpFIBTransaction * Transaction = {read = get_Transaction , write = set_Transaction};
   virtual TpFIBTransaction * get_Transaction(void)=0;
   virtual void set_Transaction(TpFIBTransaction * Transaction)=0;

};
#define IID_IDMQueryRead __uuidof(IDMQueryRead)
#endif
