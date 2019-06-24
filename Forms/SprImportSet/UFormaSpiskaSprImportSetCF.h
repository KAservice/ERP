#ifndef UFormaSpiskaSprImportSetCFH                  
#define UFormaSpiskaSprImportSetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprImportSetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprImportSetCF();                                                           
   ~TFormaSpiskaSprImportSetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
