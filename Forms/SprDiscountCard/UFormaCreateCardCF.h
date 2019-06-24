#ifndef UFormaCreateCardCFH                  
#define UFormaCreateCardCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaCreateCardCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaCreateCardCF();                                                           
   ~TFormaCreateCardCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
