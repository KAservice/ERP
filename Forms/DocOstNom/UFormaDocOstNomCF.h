#ifndef UFormaDocOstNomCFH                  
#define UFormaDocOstNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocOstNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocOstNomCF();                                                           
   ~TFormaDocOstNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
