#ifndef UFormaElementaStorageLocationCFH                  
#define UFormaElementaStorageLocationCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaStorageLocationCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaStorageLocationCF();                                                           
   ~TFormaElementaStorageLocationCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
