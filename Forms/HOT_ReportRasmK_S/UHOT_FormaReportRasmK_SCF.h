#ifndef UHOT_FormaReportRasmK_SCFH                  
#define UHOT_FormaReportRasmK_SCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaReportRasmK_SCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaReportRasmK_SCF();                                                           
   ~THOT_FormaReportRasmK_SCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
