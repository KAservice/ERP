#ifndef UFormaSpiskaSprVesNomCFH                  
#define UFormaSpiskaSprVesNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprVesNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprVesNomCF();                                                           
   ~TFormaSpiskaSprVesNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
