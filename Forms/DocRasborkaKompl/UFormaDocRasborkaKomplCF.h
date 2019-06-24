#ifndef UFormaDocRasborkaKomplCFH                  
#define UFormaDocRasborkaKomplCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRasborkaKomplCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRasborkaKomplCF();                                                           
   ~TFormaDocRasborkaKomplCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
