#ifndef UREM_DMDocOstNomCFH                  
#define UREM_DMDocOstNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocOstNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocOstNomCF();                                                           
   ~TREM_DMDocOstNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
