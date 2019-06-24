#ifndef UFormaElementaSprImportSetCFH                  
#define UFormaElementaSprImportSetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprImportSetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprImportSetCF();                                                           
   ~TFormaElementaSprImportSetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
