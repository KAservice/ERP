#ifndef UFormaPodboraNomCFH                  
#define UFormaPodboraNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaPodboraNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaPodboraNomCF();                                                           
   ~TFormaPodboraNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
