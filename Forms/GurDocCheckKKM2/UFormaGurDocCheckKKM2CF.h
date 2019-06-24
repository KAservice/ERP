#ifndef UFormaGurDocCheckKKM2CFH                  
#define UFormaGurDocCheckKKM2CFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaGurDocCheckKKM2CF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaGurDocCheckKKM2CF();                                                           
   ~TFormaGurDocCheckKKM2CF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
