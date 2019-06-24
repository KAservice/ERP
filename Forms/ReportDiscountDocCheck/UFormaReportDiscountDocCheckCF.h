#ifndef UFormaReportDiscountDocCheckCFH                  
#define UFormaReportDiscountDocCheckCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportDiscountDocCheckCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportDiscountDocCheckCF();                                                           
   ~TFormaReportDiscountDocCheckCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
