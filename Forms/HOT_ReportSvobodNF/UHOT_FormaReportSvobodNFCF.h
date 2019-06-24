#ifndef UHOT_FormaReportSvobodNFCFH                  
#define UHOT_FormaReportSvobodNFCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaReportSvobodNFCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaReportSvobodNFCF();                                                           
   ~THOT_FormaReportSvobodNFCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
