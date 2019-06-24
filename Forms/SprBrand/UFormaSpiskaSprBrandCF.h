#ifndef UFormaSpiskaSprBrandCFH                  
#define UFormaSpiskaSprBrandCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprBrandCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprBrandCF();                                                           
   ~TFormaSpiskaSprBrandCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
