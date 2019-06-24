#ifndef UFormaGurDocCheckKKMCFH                  
#define UFormaGurDocCheckKKMCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaGurDocCheckKKMCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaGurDocCheckKKMCF();                                                           
   ~TFormaGurDocCheckKKMCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
