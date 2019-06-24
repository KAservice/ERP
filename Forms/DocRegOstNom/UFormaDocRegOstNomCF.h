#ifndef UFormaDocRegOstNomCFH                  
#define UFormaDocRegOstNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRegOstNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRegOstNomCF();                                                           
   ~TFormaDocRegOstNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
