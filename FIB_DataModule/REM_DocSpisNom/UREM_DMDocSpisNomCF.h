#ifndef UREM_DMDocSpisNomCFH                  
#define UREM_DMDocSpisNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocSpisNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocSpisNomCF();                                                           
   ~TREM_DMDocSpisNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
