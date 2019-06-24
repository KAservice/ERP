#ifndef UDMDocRasborkaKomplCFH                  
#define UDMDocRasborkaKomplCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocRasborkaKomplCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocRasborkaKomplCF();                                                           
   ~TDMDocRasborkaKomplCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
