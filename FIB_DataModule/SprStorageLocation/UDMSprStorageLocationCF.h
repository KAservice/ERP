#ifndef UDMSprStorageLocationCFH                  
#define UDMSprStorageLocationCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprStorageLocationCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprStorageLocationCF();                                                           
   ~TDMSprStorageLocationCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
