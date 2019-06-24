#ifndef UREM_FormaDocOstNomCFH                  
#define UREM_FormaDocOstNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocOstNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocOstNomCF();                                                           
   ~TREM_FormaDocOstNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
