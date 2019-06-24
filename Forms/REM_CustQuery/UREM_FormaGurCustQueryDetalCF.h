#ifndef UREM_FormaGurCustQueryDetalCFH                  
#define UREM_FormaGurCustQueryDetalCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaGurCustQueryDetalCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaGurCustQueryDetalCF();                                                           
   ~TREM_FormaGurCustQueryDetalCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
