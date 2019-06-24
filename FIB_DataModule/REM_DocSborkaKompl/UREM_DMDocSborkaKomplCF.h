#ifndef UREM_DMDocSborkaKomplCFH                  
#define UREM_DMDocSborkaKomplCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocSborkaKomplCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocSborkaKomplCF();                                                           
   ~TREM_DMDocSborkaKomplCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
