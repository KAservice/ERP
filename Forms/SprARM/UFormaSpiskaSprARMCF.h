#ifndef UFormaSpiskaSprARMCFH                  
#define UFormaSpiskaSprARMCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprARMCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprARMCF();                                                           
   ~TFormaSpiskaSprARMCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
