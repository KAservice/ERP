#ifndef UFormaElementaSprImportEdCFH                  
#define UFormaElementaSprImportEdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprImportEdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprImportEdCF();                                                           
   ~TFormaElementaSprImportEdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
