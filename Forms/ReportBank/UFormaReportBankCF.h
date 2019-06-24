#ifndef UFormaReportBankCFH                  
#define UFormaReportBankCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportBankCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportBankCF();                                                           
   ~TFormaReportBankCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
