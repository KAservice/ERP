#ifndef UFormaElementaSprStorageLocationGrpCFH                  
#define UFormaElementaSprStorageLocationGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprStorageLocationGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprStorageLocationGrpCF();                                                           
   ~TFormaElementaSprStorageLocationGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
