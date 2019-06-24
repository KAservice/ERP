#ifndef UFormaElementaExtModuleCFH                  
#define UFormaElementaExtModuleCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaExtModuleCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaExtModuleCF();                                                           
   ~TFormaElementaExtModuleCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
