#ifndef UFormaDocSborkaKomplCFH                  
#define UFormaDocSborkaKomplCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocSborkaKomplCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocSborkaKomplCF();                                                           
   ~TFormaDocSborkaKomplCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
