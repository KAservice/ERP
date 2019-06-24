#ifndef UFormaExportDocCFH                  
#define UFormaExportDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaExportDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaExportDocCF();                                                           
   ~TFormaExportDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
