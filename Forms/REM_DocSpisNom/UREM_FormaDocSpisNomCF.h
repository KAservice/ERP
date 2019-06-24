#ifndef UREM_FormaDocSpisNomCFH                  
#define UREM_FormaDocSpisNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocSpisNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocSpisNomCF();                                                           
   ~TREM_FormaDocSpisNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
