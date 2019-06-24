#ifndef UFormaUnReportCFH                  
#define UFormaUnReportCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaUnReportCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaUnReportCF();                                                           
   ~TFormaUnReportCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
