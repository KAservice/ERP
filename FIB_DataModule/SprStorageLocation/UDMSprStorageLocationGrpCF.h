#ifndef UDMSprStorageLocationGrpCFH                  
#define UDMSprStorageLocationGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprStorageLocationGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprStorageLocationGrpCF();                                                           
   ~TDMSprStorageLocationGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
