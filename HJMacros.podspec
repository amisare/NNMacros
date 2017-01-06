Pod::Spec.new do |s|
  s.name          = "HJMacros"
  s.version       = "0.2.1"
  s.summary       = "HJMacros: Macros used in Objective-C development"

  s.description   = <<-DESC
                   HJMacros: Macros used in Objective-C development.
                   DESC

  s.homepage      = "https://github.com/amisare/HJMacros"
  s.license       = { :type => "MIT", :file => "LICENSE" }
  s.author        = { "Haijun Gu" => "243297288@qq.com" }
  s.social_media_url        = "http://www.jianshu.com/users/9df9f28ff266/latest_articles"

  s.source        = { :git => "https://github.com/amisare/HJMacros.git", :tag => s.version }
  s.ios.deployment_target   = '6.0'
  s.osx.deployment_target   = '10.8'
  s.requires_arc  = true

  s.source_files  = 'HJMacros/*.{h,m}'

  s.default_subspec         = 'Bases'
  s.subspec 'Bases' do |ss|
    ss.source_files         = 'HJMacros/Bases/*.{h,m}'
  end

end
