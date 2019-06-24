#ifndef UFormaElementaSprStorageLocationCFH                  
#define UFormaElementaSprStorageLocationCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprStorageLocationCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprStorageLocationCF();                                                           
   ~TFormaElementaSprStorageLocationCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
