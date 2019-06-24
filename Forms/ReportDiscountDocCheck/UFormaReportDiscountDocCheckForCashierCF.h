#ifndef UFormaReportDiscountDocCheckForCashierCFH                  
#define UFormaReportDiscountDocCheckForCashierCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportDiscountDocCheckForCashierCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportDiscountDocCheckForCashierCF();                                                           
   ~TFormaReportDiscountDocCheckForCashierCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
