#ifndef UDMGurDocCheckKKM2CFH                  
#define UDMGurDocCheckKKM2CFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMGurDocCheckKKM2CF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMGurDocCheckKKM2CF();                                                           
   ~TDMGurDocCheckKKM2CF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
