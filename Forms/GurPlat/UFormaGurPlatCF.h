#ifndef UFormaGurPlatCFH                  
#define UFormaGurPlatCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaGurPlatCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaGurPlatCF();                                                           
   ~TFormaGurPlatCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
