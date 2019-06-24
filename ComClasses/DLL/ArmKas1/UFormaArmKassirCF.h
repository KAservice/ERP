#ifndef UFormaArmKassirCFH                  
#define UFormaArmKassirCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaArmKassirCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaArmKassirCF();                                                           
   ~TFormaArmKassirCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
