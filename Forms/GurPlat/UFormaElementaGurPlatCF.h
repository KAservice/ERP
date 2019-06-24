#ifndef UFormaElementaGurPlatCFH                  
#define UFormaElementaGurPlatCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaGurPlatCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaGurPlatCF();                                                           
   ~TFormaElementaGurPlatCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
