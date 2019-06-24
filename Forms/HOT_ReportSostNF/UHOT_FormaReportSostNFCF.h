#ifndef UHOT_FormaReportSostNFCFH                  
#define UHOT_FormaReportSostNFCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaReportSostNFCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaReportSostNFCF();                                                           
   ~THOT_FormaReportSostNFCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
