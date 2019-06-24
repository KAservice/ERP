#ifndef UFormaSpiskaSprGrafikPlatCFH                  
#define UFormaSpiskaSprGrafikPlatCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprGrafikPlatCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprGrafikPlatCF();                                                           
   ~TFormaSpiskaSprGrafikPlatCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
