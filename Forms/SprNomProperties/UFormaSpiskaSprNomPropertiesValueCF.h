#ifndef UFormaSpiskaSprNomPropertiesValueCFH                  
#define UFormaSpiskaSprNomPropertiesValueCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprNomPropertiesValueCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprNomPropertiesValueCF();                                                           
   ~TFormaSpiskaSprNomPropertiesValueCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
