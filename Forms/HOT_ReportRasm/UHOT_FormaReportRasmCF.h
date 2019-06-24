#ifndef UHOT_FormaReportRasmCFH                  
#define UHOT_FormaReportRasmCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaReportRasmCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaReportRasmCF();                                                           
   ~THOT_FormaReportRasmCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
