#ifndef UFormaSpiskaSprNomRestCFH                  
#define UFormaSpiskaSprNomRestCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprNomRestCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprNomRestCF();                                                           
   ~TFormaSpiskaSprNomRestCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
